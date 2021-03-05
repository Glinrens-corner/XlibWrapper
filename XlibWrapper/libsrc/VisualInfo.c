#include "X11Wrapper.h"

int get_color_map_class(XVisualInfo* info ){
  return info->class;
}

