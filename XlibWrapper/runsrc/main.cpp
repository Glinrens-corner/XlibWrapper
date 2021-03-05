
#include "X11Wrapper.hpp"
#include <iostream>
#include <unistd.h>
#include <memory>

constexpr int width = 300;
constexpr int height = 400;

x11::Image create_image(x11::Display&dpl,
			x11::VisualInfo& visual_info
			){
  constexpr int bits_per_pixel= 32;
  constexpr int bytes_per_pixel = bits_per_pixel/8;
  constexpr int window_buffer_size = width*height*bytes_per_pixel;
  
  char* image_data{static_cast<char*>(std::malloc(window_buffer_size ))};
  return dpl.create_image(visual_info.visual(),
			  visual_info.depth(),
			  x11::ImageFormat::ZPixmap, 0, image_data,
			  width, height , bits_per_pixel, 0);
};


int main(){
  using namespace x11;
  auto dpl = Display(nullptr);
  GCValues val =GCValues{}
     .with_foreground(dpl.white_pixel(dpl.default_screen()))
     .with_background(dpl.white_pixel(dpl.default_screen()))
     .with_fill_style(FillStyle::Solid)
     .with_line_width(10)
     .with_cap_style(CapStyle::Round)
     .with_join_style(JoinStyle::Round);

  auto visual_info = dpl.match_visual_info(dpl.default_screen() , 24, ColorClass::TrueColor);
  auto image = create_image(dpl,visual_info);
  std::cout <<"width: " << image.width() << " height: "<< image.height() << " is null " << not static_cast<bool>(image.data() ) << std::endl;;
  for ( int y=0; y< image.height() ; y++){
    for ( int x = 0; x<image.width(); x++){
      char * pixel_ptr = image.data() + image.bytes_per_pixel()*x+image.width()*y*image.bytes_per_pixel();
      
      if ((y%100 < 50 )and (x%100 <50)  ) {
	pixel_ptr[0] = 0x00;
	pixel_ptr[1] = 0xf0;
	pixel_ptr[2] = 0x00;
	pixel_ptr[3] = 0xFF;
      } else {
	pixel_ptr[0] = 0xff;
	pixel_ptr[1] = 0xff;
	pixel_ptr[2] = 0xff;
	pixel_ptr[3] = 0x00;

      }
    };
  };
  
  // DrawableId win = dpl.create_window(
  DrawableId win = dpl.create_window(dpl.root_window(dpl.default_screen()),
				     0,0,
				     width,height,0,
				     visual_info.depth(),
				     ColorClass::TrueColor,
				     visual_info.visual(),
				     SetWindowAttributes{}.with_background_pixel(0) );
  GC gc = dpl.create_gc(win, val);
  Event event{};
  dpl.select_input(win, EventMask::Exposure|EventMask::StructureNotify);
  dpl.map_window(win);
  std::vector<AtomId>wm_protocols{dpl.intern_atom( "WM_DELETE_WINDOW", false)};
  if(! dpl.set_wm_protocols(win,wm_protocols)){

    throw std::exception();
  };
  dpl.sync(false);
  bool end=false;
  while ( not end){
    dpl.next_event(event);
    std::cout << string_from_event_type(event.type()) << std::endl;
    switch(event.type()){
    case EventType::Expose:
      // dpl.fill_rectangle(win,gc,50,50,100,100 );
      // dpl.draw_rectangle(win,gc,30,30,140,140 );
      // dpl.draw_point( win,gc, -1,-5 );
      dpl.put_image(win, gc, image, 0,0,0,0,image.width(), image.height());
      
      break;
    case EventType::ClientMessage:
      dpl.destroy_window(win);
      end = true;
      break;
    default:
      break;
    };

  }
 
  std::cout << dpl.screen_count() <<" " << dpl.default_screen()<< std::endl;
  return 0;
}
