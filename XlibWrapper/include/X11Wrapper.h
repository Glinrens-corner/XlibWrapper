#ifndef X11WRAPPER_H
#define X11WRAPPER_H

#include <X11/Xutil.h>


#ifdef __cplusplus
extern "C" {
#endif
  
int get_color_map_class(XVisualInfo* info );

#ifdef __cplusplus
}
#endif 
#endif //  X11WRAPPER_H
