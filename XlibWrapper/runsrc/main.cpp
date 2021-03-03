
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
  dpl.select_input(win, ); 
  dpl.map_window(win);
  dpl.sync(false);
		   
  while ( 1){
    dpl.next_event(event);
    switch(event.type()){
    case EventType::ExposeType:
      dpl.draw_rectangle(win,gc,50,50,100,100 );
      dpl.fill_rectangle(win,gc,50,50,100,100 );
      dpl.draw_point( win,gc, -1,-5 );
      break;
    default:
      break;
    };

  }
 
  dpl.sync(false);
  std::cout << dpl.screen_count() <<" " << dpl.default_screen()<< std::endl;
  sleep(10);
  return 0;
}
