
#include "X11Wrapper.hpp"
#include <iostream>
#include <unistd.h>




int main(){
  using namespace x11;
  auto dpl = Display(nullptr);
  GCValues val =GCValues{}
     .with_foreground(dpl.black_pixel(dpl.default_screen()))
     .with_background(dpl.black_pixel(dpl.default_screen()))
     .with_fill_style(FillStyle::Solid)
     .with_line_width(10)
     .with_cap_style(CapStyle::Round)
     .with_join_style(JoinStyle::Round);
     
  DrawableId win = dpl.create_simple_window(dpl.root_window(dpl.default_screen()),
					       0,0,
					       300,400,
					       0,dpl.white_pixel(dpl.default_screen()),
					       dpl.white_pixel(dpl.default_screen()));
  GC gc = dpl.create_gc(win, val);
  Event event{};
  dpl.select_input(win, EventMask::Exposure|EventMask::StructureNotify);
  auto visual_info = dpl.match_visual_info(dpl.default_screen() , 24, ColorClass::TrueColor);
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
      dpl.fill_rectangle(win,gc,50,50,100,100 );
      dpl.draw_rectangle(win,gc,30,30,140,140 );
      dpl.draw_point( win,gc, -1,-5 );
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
