#include "X11Wrapper.hpp"
#include "X11Wrapper.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <type_traits>
#include <exception>

constexpr int XYBitmapFormat = XYBitmap;
constexpr int XYPixmapFormat = XYPixmap;
constexpr int  ZPixmapFormat =  ZPixmap;

#undef XYBitmap
#undef XYPixmap
#undef  ZPixmap

constexpr int StaticGrayClass = StaticGray;
constexpr int GrayScaleClass = GrayScale;
constexpr int StaticColorClass = StaticColor;
constexpr int PseudoColorClass = PseudoColor;
constexpr int TrueColorClass = TrueColor;
constexpr int DirectColorClass = DirectColor;

#undef StaticGray
#undef GrayScale
#undef StaticColor
#undef PseudoColor
#undef TrueColor
#undef DirectColor


constexpr unsigned long KeyPressType = KeyPress ; 
constexpr unsigned long KeyReleaseType = KeyRelease ; 
constexpr unsigned long ButtonPressType = ButtonPress ; 
constexpr unsigned long ButtonReleaseType = ButtonRelease ; 
constexpr unsigned long MotionNotifyType = MotionNotify ; 
constexpr unsigned long EnterNotifyType = EnterNotify ; 
constexpr unsigned long LeaveNotifyType = LeaveNotify ; 
constexpr unsigned long FocusInType = FocusIn ; 
constexpr unsigned long FocusOutType = FocusOut ; 
constexpr unsigned long KeymapNotifyType = KeymapNotify ; 
constexpr unsigned long ExposeType = Expose ; 
constexpr unsigned long GraphicsExposeType = GraphicsExpose ; 
constexpr unsigned long NoExposeType = NoExpose ; 
constexpr unsigned long CirculateRequestType = CirculateRequest ; 
constexpr unsigned long ConfigureRequestType = ConfigureRequest ; 
constexpr unsigned long MapRequestType = MapRequest ; 
constexpr unsigned long ResizeRequestType = ResizeRequest ; 
constexpr unsigned long CirculateNotifyType = CirculateNotify ; 
constexpr unsigned long ConfigureNotifyType = ConfigureNotify ; 
constexpr unsigned long CreateNotifyType = CreateNotify ; 
constexpr unsigned long DestroyNotifyType = DestroyNotify ; 
constexpr unsigned long GravityNotifyType = GravityNotify ; 
constexpr unsigned long MapNotifyType = MapNotify ; 
constexpr unsigned long MappingNotifyType = MappingNotify ; 
constexpr unsigned long ReparentNotifyType = ReparentNotify ; 
constexpr unsigned long UnmapNotifyType = UnmapNotify ; 
constexpr unsigned long VisibilityNotifyType = VisibilityNotify ; 
constexpr unsigned long ColormapNotifyType = ColormapNotify ; 
constexpr unsigned long ClientMessageType = ClientMessage ; 
constexpr unsigned long PropertyNotifyType = PropertyNotify ; 
constexpr unsigned long SelectionClearType = SelectionClear ; 
constexpr unsigned long SelectionNotifyType = SelectionNotify ; 
constexpr unsigned long SelectionRequestType = SelectionRequest ; 

#undef KeyPress 
#undef KeyRelease 
#undef ButtonPress 
#undef ButtonRelease 
#undef MotionNotify 
#undef EnterNotify 
#undef LeaveNotify 
#undef FocusIn 
#undef FocusOut 
#undef KeymapNotify 
#undef Expose 
#undef GraphicsExpose 
#undef NoExpose 
#undef CirculateRequest 
#undef ConfigureRequest 
#undef MapRequest 
#undef ResizeRequest 
#undef CirculateNotify 
#undef ConfigureNotify 
#undef CreateNotify 
#undef DestroyNotify 
#undef GravityNotify 
#undef MapNotify 
#undef MappingNotify 
#undef ReparentNotify 
#undef UnmapNotify 
#undef VisibilityNotify 
#undef ColormapNotify 
#undef ClientMessage 
#undef PropertyNotify 
#undef SelectionClear 
#undef SelectionNotify 
#undef SelectionRequest 

namespace x11{
  unsigned long all_planes(){return XAllPlanes();};
}


namespace x11{
  struct NativeConverter{
    static constexpr int convert(x11::GCFunctionValue fun){
      switch( fun){
      case x11::GCFunctionValue::Clear:
	return GXclear;
	break;
      case x11::GCFunctionValue::And:
	return GXand;
	break;
      case x11::GCFunctionValue::AndReverse:
	return GXandReverse;
	break;
      case x11::GCFunctionValue::Copy:
	return GXcopy;
	break;
      case x11::GCFunctionValue::AndInverted:
	return GXandInverted;
	break;
      case x11::GCFunctionValue::Noop:
	return GXnoop;
	break;
      case x11::GCFunctionValue::Xor:
	return GXxor;
	break;
      case x11::GCFunctionValue::Or:
	return GXor;
	break;
      case x11::GCFunctionValue::Nor:
	return GXnor;
	break;
      case x11::GCFunctionValue::Equiv:
	return GXequiv;
	break;
      case x11::GCFunctionValue::Invert:
	return GXinvert;
	break;
      case x11::GCFunctionValue::OrReverse:
	return GXor;
	break;
      case x11::GCFunctionValue::CopyInverted:
	return GXcopyInverted;
	break;
      case x11::GCFunctionValue::OrInverted:
	return GXorInverted;
	break;
      case x11::GCFunctionValue::Nand:
	return GXnand;
	break;
      case x11::GCFunctionValue::Set:
	return GXset;
	break;
      };
    };
    static constexpr int convert(LineStyle style){
      switch(style){
      case LineStyle::Solid:
	return LineSolid;
	break;
      case LineStyle::DoubleDash:
	return LineDoubleDash;
	break;
      case LineStyle::OnOffDash:
	return LineOnOffDash;
	break;
      }
    }
    static constexpr int convert(CapStyle style){
      switch(style){
      case CapStyle::NotLast:
	return CapNotLast;
	break;
      case CapStyle::Butt:
	return CapButt;
	break;
      case CapStyle::Round:
	return CapRound;
	break;
      case CapStyle::Projecting:
	return CapProjecting;
	break;
      };
    }
    static constexpr int convert(JoinStyle style){
      switch(style){
      case JoinStyle::Miter:
	return JoinMiter;
	break;
      case JoinStyle::Round:
	return JoinRound;
	break;
      case JoinStyle::Bevel:
	return JoinBevel;
	break;
      };
    }
    static constexpr int convert(FillStyle style){
      switch(style){
      case FillStyle::Solid:
	return FillSolid;
	break;
      case FillStyle::Tiled:
	return FillTiled;
	break;
      case FillStyle::OpaqueStippled:
	return FillOpaqueStippled;
	break;
      case FillStyle::Stippled:
	return FillStippled;
	break;
      };
    }
    static constexpr ::GC convert(x11::GC& gc ){
      static_assert(not std::is_same<typename std::remove_pointer<::GC>::type, ::GC>::value, "It seems GC is not a pointer type..." );
      return static_cast<::GC>(gc.impl_);
    };
    static constexpr ::XGCValues convert(const x11::GCValues& values){
#define TRANSFER(NAME) .NAME = values.NAME ## _
      
      return ::XGCValues{
	TRANSFER(function),
	  TRANSFER(plane_mask),
	  TRANSFER(foreground),
	  TRANSFER(background),
	  TRANSFER(line_width),
	  TRANSFER(line_style),
	  TRANSFER(cap_style),
	  TRANSFER(join_style),
	  TRANSFER(fill_style),
	  TRANSFER(fill_rule),
	  TRANSFER(arc_mode),
	  TRANSFER(tile),
	  TRANSFER(stipple),
	  TRANSFER(ts_x_origin),
	  TRANSFER(ts_y_origin),
	  TRANSFER(font),
	  TRANSFER(subwindow_mode),
	  TRANSFER(graphics_exposures),
	  TRANSFER(clip_x_origin),
	  TRANSFER(clip_y_origin),
	  TRANSFER(clip_mask),
	  TRANSFER(dash_offset),
	  TRANSFER(dashes)
#undef TRANSFER
      };
    }
    static constexpr int convert(ColorClass color_class){
#define CASE(NAME)\
      case ColorClass::NAME:\
	return NAME ## Class;\
	break;

      switch(color_class){
	CASE(StaticGray)
	  CASE(GrayScale)
	  CASE(StaticColor)
	  CASE(PseudoColor)
	  CASE(TrueColor)
	  CASE(DirectColor)
	}
#undef CASE
    };
    static constexpr int convert(ImageFormat image_format){
      switch(image_format){
      case ImageFormat::XYBitmap:
	return XYBitmapFormat;
	break;
      case ImageFormat::XYPixmap:
	return XYPixmapFormat;
	break;
      case ImageFormat::ZPixmap:
	return ZPixmapFormat;
	break;
      };

    };
    static constexpr ::XEvent * access(x11::Event& event){
      return static_cast<::XEvent*>(event.impl_);
    };
    static constexpr ::XVisualInfo* access( x11::VisualInfo& info){
      return static_cast<::XVisualInfo *>(info.impl_);
    };
    static constexpr ::XImage * access ( x11::Image& image){
      return static_cast<::XImage*>( image.impl_);
    };
    static constexpr ::Visual* access( x11::Visual& visual){
      return static_cast<::Visual*>(visual.impl_ );
    };
    static constexpr ::XSetWindowAttributes convert(const x11::SetWindowAttributes& attributes ){
#define TRANSFER(NAME) .NAME = attributes.NAME ## _
#define TRANSFERC(NAME) .NAME = NativeConverter::convert(attributes.NAME ## _)
      
      return ::XSetWindowAttributes{
	TRANSFER( background_pixmap),
	  TRANSFER( background_pixel),
	  TRANSFER( border_pixmap),
	  TRANSFER( border_pixel),
	  TRANSFER( bit_gravity),
	  TRANSFER( win_gravity),
	  TRANSFER( backing_store),
	  TRANSFER( backing_planes),
	  TRANSFER( backing_pixel),
	  TRANSFER( save_under),
	  TRANSFER( event_mask),
	  TRANSFER( do_not_propagate_mask),
	  TRANSFER( override_redirect),
	  TRANSFER( colormap),
	  TRANSFER( cursor)
	  };
    };
  };
  
}

// GC
namespace x11 {
  GCValues& GCValues::with_function(GCFunctionValue fun ){
    this->function_ = NativeConverter::convert(fun);
    this->valuemask_ |=  GCFunction;
    return *this;
  }; 
  GCValues& GCValues::with_plane_mask(unsigned long plane_mask ){
    this->plane_mask_ = plane_mask;
    this->valuemask_ |=  GCPlaneMask;
    return *this;
  }; 
  GCValues& GCValues::with_foreground(unsigned long foreground ){
    this->foreground_ = foreground;
    this->valuemask_ |=  GCForeground;
    return *this;
  }; 
  GCValues& GCValues::with_background(unsigned long background ){
    this->background_ = background;
    this->valuemask_ |=  GCBackground;
    return *this;
  }; 
  GCValues& GCValues::with_line_width(int width ){
    this->line_width_ = width;
    this->valuemask_ |=  GCLineWidth;
    return *this;
  }; 
  GCValues& GCValues::with_line_style(LineStyle style ){
    this->line_style_ = NativeConverter::convert(style);
    this->valuemask_ |=  GCLineStyle;
    return *this;
  }; 
  GCValues& GCValues::with_cap_style(CapStyle style ){
    this->cap_style_ = NativeConverter::convert(style);
    this->valuemask_ |=  GCCapStyle;
    return *this;
  }; 
  GCValues& GCValues::with_join_style(JoinStyle style ){
    this->join_style_ = NativeConverter::convert(style);
    this->valuemask_ |=  GCJoinStyle;
    return *this;
  }; 
  GCValues& GCValues::with_fill_style(FillStyle style ){
    this->fill_style_ = NativeConverter::convert(style);
    this->valuemask_ |=  GCFillStyle;
    return *this;
  }; 

  


}

// VisualInfo
namespace x11 {
  VisualInfo::VisualInfo(){this->impl_=static_cast<void*>( new ::XVisualInfo{}); };
  VisualInfo::~VisualInfo(){delete static_cast<::XVisualInfo*>( this->impl_ ) ;};
  unsigned int VisualInfo::depth(){return NativeConverter::access(*this)->depth;};
  Visual VisualInfo::visual(){return Visual( reinterpret_cast<void*>(NativeConverter::access(*this)->visual));};
  int VisualInfo::screen(){return NativeConverter::access(*this)->screen;};
  
  int VisualInfo::color_class()  { return ::get_color_map_class(NativeConverter::access(*this)); }
  unsigned long VisualInfo::red_mask(){return NativeConverter::access(*this)->red_mask;};
  unsigned long VisualInfo::green_mask(){return NativeConverter::access(*this)->green_mask;};
  unsigned long VisualInfo::blue_mask(){return NativeConverter::access(*this)->blue_mask;};
  
  int VisualInfo::colormap_size(){return NativeConverter::access(*this)->colormap_size;}
  int VisualInfo::bits_per_rgb(){return NativeConverter::access(*this)->bits_per_rgb;};
};

// Visual
namespace x11 {
   Visual::Visual(void * impl):impl_(impl){};
}

// Image
namespace x11 {
  Image::Image(void * impl): impl_(impl){};
  Image::~Image(){};
  char * Image::data(){ return NativeConverter::access(*this)->data;}
  int Image::width(){ return NativeConverter::access(*this)->width;}
  int  Image::height(){ return NativeConverter::access(*this)->height;}
  int Image::bits_per_pixel(){return NativeConverter::access(*this)->bits_per_pixel;}
  int Image::bytes_per_pixel(){return this->bits_per_pixel()/8;};
}

// SetWindowAttributes
namespace x11  {
#define IMPL(TYPE, NAME,  MASK)					       \
  SetWindowAttributes& SetWindowAttributes::with_ ## NAME(TYPE  NAME){ \
    this->valuemask_ |= MASK;					       \
    this->NAME ##_ = NAME;					       \
    return *this ;						       \
  }     
IMPL(Pixmap, background_pixmap, CWBackPixmap)
IMPL(unsigned long, background_pixel, CWBackPixel)
IMPL(Pixmap, border_pixmap, CWBorderPixmap)
IMPL(unsigned long, border_pixel, CWBorderPixel)
IMPL(int, bit_gravity, CWBitGravity)
IMPL(int, win_gravity, CWWinGravity)
IMPL(int, backing_store, CWBackingStore)
IMPL(unsigned long, backing_planes, CWBackingPlanes)
IMPL(unsigned long, backing_pixel, CWBackingPixel)
IMPL(bool, save_under, CWSaveUnder)
IMPL(long, event_mask, CWEventMask)
IMPL(long, do_not_propagate_mask, CWDontPropagate)
IMPL(bool, override_redirect, CWOverrideRedirect)
IMPL(Colormap, colormap, CWColormap)
IMPL(Cursor, cursor, CWCursor)

#undef IMPL
};

//Event
namespace x11 {
  EventType event_type_from_native_type( int type){
#define CASE(TYPE)					\
    case TYPE## Type:					\
      return EventType::TYPE ;				\
      break;
    
    switch (type){
      CASE(KeyPress)
	CASE(KeyRelease)
	CASE(ButtonPress)
	CASE(ButtonRelease)
	CASE(MotionNotify)
	CASE(EnterNotify)
	CASE(LeaveNotify)
	CASE(FocusIn)
	CASE(FocusOut)
	CASE(KeymapNotify)
	CASE(Expose)
	CASE(GraphicsExpose)
	CASE(NoExpose)
	CASE(CirculateRequest)
	CASE(ConfigureRequest)
	CASE(MapRequest)
	CASE(ResizeRequest)
	CASE(CirculateNotify)
	CASE(ConfigureNotify)
	CASE(CreateNotify)
	CASE(DestroyNotify)
	CASE(GravityNotify)
	CASE(MapNotify)
	CASE(MappingNotify)
	CASE(ReparentNotify)
	CASE(UnmapNotify)
	CASE(VisibilityNotify)
	CASE(ColormapNotify)
	CASE(ClientMessage)
	CASE(PropertyNotify)
	CASE(SelectionClear)
	CASE(SelectionNotify)
	CASE(SelectionRequest)
    default: // this should never happen
      return EventType::Unknown;
    };
#undef CASE
  };
  std::string string_from_event_type(EventType type){
#define CASE(NAME) \
    case EventType::NAME :		\
      return #NAME ; \
      break;
    switch(type){
      CASE(KeyPress)
	CASE(KeyRelease)
	CASE(ButtonPress)
	CASE(ButtonRelease)
	CASE(MotionNotify)
	CASE(EnterNotify)
	CASE(LeaveNotify)
	CASE(FocusIn)
	CASE(FocusOut)
	CASE(KeymapNotify)
	CASE(Expose)
	CASE(GraphicsExpose)
	CASE(NoExpose)
	CASE(CirculateRequest)
	CASE(ConfigureRequest)
	CASE(MapRequest)
	CASE(ResizeRequest)
	CASE(CirculateNotify)
	CASE(ConfigureNotify)
	CASE(CreateNotify)
	CASE(DestroyNotify)
	CASE(GravityNotify)
	CASE(MapNotify)
	CASE(MappingNotify)
	CASE(ReparentNotify)
	CASE(UnmapNotify)
	CASE(VisibilityNotify)
	CASE(ColormapNotify)
	CASE(ClientMessage)
	CASE(PropertyNotify)
	CASE(SelectionClear)
	CASE(SelectionNotify)
	CASE(SelectionRequest)
	CASE(Unknown)
	
	}
#undef CASE
  };

  
  Event::Event() { this->impl_= static_cast<void*>(new ::XEvent{});};
  Event::~Event(){delete static_cast<::XEvent*>(this->impl_);};
  EventType Event::type()  { return event_type_from_native_type(static_cast<::XEvent*>(this->impl_)->type); };
}

// Display
namespace x11 {
  VisualInfo Display::match_visual_info(int screen_num, int depth, ColorClass color_class) {
      VisualInfo info{};
      if (! XMatchVisualInfo(this->impl,screen_num, depth, NativeConverter::convert(color_class), NativeConverter::access(info))){
	throw std::exception{};
      }
      return info;
  };
  DrawableId Display::root_window( int screen_num) {return  RootWindow( this->impl, screen_num); };
  Image Display::create_image(Visual visual,
			      unsigned int depth,
			      ImageFormat format,
			      int offset,
			      char* data,
			      unsigned int width, unsigned int height,
			      int bitmap_pad, int bytes_per_line
			      ){
    return Image(reinterpret_cast<void*>(XCreateImage(this->impl,
						      NativeConverter::access(visual),
						      depth,
						      NativeConverter::convert(format),
						      offset,
						      data,
						      width, height,
						      bitmap_pad,
						      bytes_per_line
						      )
					 )
		 );
  };

  DrawableId Display::create_window(DrawableId parent,
				    int x, int y,
				    unsigned int width,
				    unsigned int height,
				    unsigned int border_width,
				    int depth,
				    ColorClass color_class,
				    Visual visual,
				    const SetWindowAttributes& attributes){
    auto attrib = NativeConverter::convert(attributes);
    return XCreateWindow(this->impl, parent,
			 x,y,
			 width, height,
			 border_width,
			 depth ,
			 InputOutput,
			 NativeConverter::access(visual),
			 attributes.valuemask(),
			 &attrib);
  };
  int Display::display_height(int screen_number){
    return XDisplayHeight(this->impl, screen_number);
  };
  int Display::display_height_mm(int screen_number){
    return XDisplayHeightMM(this->impl, screen_number);

  };
  int Display::display_width(int screen_number){
    return XDisplayWidth(this->impl, screen_number);

  };
  int Display::display_width_mm(int screen_number){
    return XDisplayWidthMM(this->impl, screen_number);
  };

  void Display::put_image(DrawableId window,
			  GC gc,
			  Image image,
			  int src_x, int src_y,
			  int dest_x, int dest_y,
			  unsigned int width, unsigned int height){
    
    XPutImage(this->impl, window, NativeConverter::convert(gc),
	      NativeConverter::access(image),
	      src_x, src_y, dest_x, dest_y,
	      width, height);
	      
  };
		     
  DrawableId Display::create_simple_window(DrawableId parent,
					 int win_x, int win_y,
					 unsigned int width, unsigned int height,
					 unsigned int border_width,
					 unsigned long border,
					 unsigned long background){ return XCreateSimpleWindow(this->impl,parent,win_x,win_y,width,height,border_width,
											       border, background);};
  x11::GC Display::create_gc(DrawableId win , const GCValues& values){
    auto native_values = NativeConverter::convert(values);
    ::GC gc = XCreateGC(this->impl, win, values.valuemask(), &native_values );
    if (!gc){
      throw std::exception( );
    };
    
    return x11::GC( static_cast<void*>(gc));
  };
  AtomId Display::intern_atom(const std::string& atom_name, bool only_if_exists ){return XInternAtom(this->impl, atom_name.c_str(), only_if_exists);}
  Status Display::set_wm_protocols(DrawableId win, const std::vector<AtomId>& protocols  ){return XSetWMProtocols( this->impl, win, const_cast<AtomId*>(protocols.data()), protocols.size()); };
  void Display::destroy_window(DrawableId win) {XDestroyWindow(this->impl, win);};
  void Display::select_input(DrawableId win,  unsigned long mask) { XSelectInput(this->impl,win ,  mask); };
  void Display::draw_point(DrawableId drawable, GC gc, int x, int y){XDrawPoint(this->impl, drawable, NativeConverter::convert(gc), x,y);}
  void Display::draw_rectangle(DrawableId drawable, GC gc, int x, int y,unsigned int width, unsigned int height){XDrawRectangle(this->impl, drawable, NativeConverter::convert(gc), x,y, width, height);}
  void Display::fill_rectangle(DrawableId drawable, GC gc, int x, int y,unsigned int width, unsigned int height){XFillRectangle(this->impl, drawable, NativeConverter::convert(gc), x,y, width, height);}
  void Display::map_window(DrawableId win){ XMapWindow(this->impl, win);};
  int Display::connection_number(){return XConnectionNumber(this->impl); };
  int Display::screen_count(){return XScreenCount(this->impl); };
  unsigned long Display::black_pixel(int screen_num){return XBlackPixel(this->impl, screen_num);}
  unsigned long Display::white_pixel(int screen_num){return XWhitePixel(this->impl, screen_num);}
  int Display::default_screen(){return XDefaultScreen(this->impl);};
  void Display::flush(){XFlush(this->impl);};
  void Display::sync(bool discard){XSync(this->impl, discard);};
  void Display::next_event(Event& event){XNextEvent(this->impl, NativeConverter::access(event)); };
  Display::~Display(){ XCloseDisplay(this->impl); };
  Display::Display(char * display_name):impl(XOpenDisplay( display_name)){
  };
}
