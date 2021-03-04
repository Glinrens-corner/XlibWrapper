#ifndef X11WRAPPER_HPP
#define X11WRAPPER_HPP
#include <memory>
#include <vector>
struct _XGC;
struct _XDisplay;

namespace x11 {
  struct NativeConverter;

  using DrawableId = unsigned long;
  using AtomId = unsigned long;
  using Status = int;
  
  
  // setting it to some type for now...
  using Pixmap = unsigned long;
  using Font = unsigned long;

  enum class   GCFunctionValue: int{
    Clear = 0x0,
      And = 0x1,
      AndReverse = 0x2,
      Copy= 0x3,
      AndInverted = 0x4,
      Noop= 0x5,
      Xor= 0x6,
      Or= 0x7,
      Nor= 0x8,
      Equiv= 0x9,
      Invert= 0xa,
      OrReverse = 0xb,
      CopyInverted= 0xc,
      OrInverted= 0xd,
      Nand= 0xe,
      Set= 0xf
  };
  
  enum class LineStyle  {
    Solid,
    DoubleDash,
    OnOffDash
  };
  
  enum class CapStyle {
    NotLast,
    Butt,
    Round,
    Projecting
  };

  enum class JoinStyle{
    Miter,
    Round,
    Bevel
  };
  
  enum class FillStyle{
    Solid,
    Tiled,
    OpaqueStippled,
    Stippled
  };

  enum class EventType{
    KeyPress,
    KeyRelease,
    ButtonPress,
    ButtonRelease,
    MotionNotify,
    EnterNotify,
    LeaveNotify,
    FocusIn,
    FocusOut,
    KeymapNotify,
    Expose,
    GraphicsExpose,
    NoExpose,
    CirculateRequest,
    ConfigureRequest,
    MapRequest,
    ResizeRequest,
    CirculateNotify,
    ConfigureNotify,
    CreateNotify,
    DestroyNotify,
    GravityNotify,
    MapNotify,
    MappingNotify,
    ReparentNotify,
    UnmapNotify,
    VisibilityNotify,
    ColormapNotify,
    ClientMessage,
    PropertyNotify,
    SelectionClear,
    SelectionNotify,
    SelectionRequest,
    Unknown
  };

  enum EventMask : unsigned long{
    NoEvent =0,
    KeyPress=(1L<<0),  
    KeyRelease=(1L<<1),  
    ButtonPress=(1L<<2),  
    ButtonRelease=(1L<<3),  
    EnterWindow=(1L<<4),  
    LeaveWindow=(1L<<5),  
    PointerMotion=(1L<<6),  
    PointerMotionHint=(1L<<7),  
    Button1Motion=(1L<<8),  
    Button2Motion=(1L<<9),  
    Button3Motion=(1L<<10), 
    Button4Motion=(1L<<11), 
    Button5Motion=(1L<<12), 
    ButtonMotion=(1L<<13), 
    KeymapState=(1L<<14),
    Exposure=(1L<<15), 
    VisibilityChange=(1L<<16), 
    StructureNotify=(1L<<17), 
    ResizeRedirect=(1L<<18), 
    SubstructureNotify=(1L<<19), 
    SubstructureRedirect=(1L<<20), 
    FocusChange=(1L<<21), 
    PropertyChange=(1L<<22), 
    ColormapChange=(1L<<23), 
    OwnerGrabButton=(1L<<24), 
    
  };
  
  std::string string_from_event_type( EventType type);					
  
  class GCValues{
    friend NativeConverter;
    
  public:
    GCValues& with_function(GCFunctionValue fun);
    GCValues& with_plane_mask(unsigned long plane_mask);
    GCValues& with_foreground(unsigned long color);
    GCValues& with_background(unsigned long color);
    GCValues& with_line_width(int line_width);
    GCValues& with_line_style(LineStyle style);
    
    GCValues& with_cap_style(CapStyle style);
    GCValues& with_join_style(JoinStyle style);
    GCValues& with_fill_style(FillStyle style);
    /*GCValues& with_fill_rule(int rulex);
    GCValues& with_arc_mode(int rule);
    */

    unsigned long valuemask()const{return valuemask_;}
  private:
    unsigned long valuemask_ = 0;
    int function_;
    unsigned long plane_mask_;
    unsigned long foreground_;
    unsigned long background_;
    int line_width_;
    int line_style_;
    int cap_style_;
    int join_style_;
    int fill_style_;
    int fill_rule_;
    int arc_mode_;
    Pixmap tile_;
    Pixmap stipple_;
    int ts_x_origin_;
    int ts_y_origin_;
    Font font_;
    int subwindow_mode_;
    bool graphics_exposures_;
    int clip_x_origin_;
    int clip_y_origin_;
    Pixmap clip_mask_;
    int dash_offset_;
    char dashes_;
  };
  
  class GC{
    friend NativeConverter;
  public:
    GC():impl_(nullptr){};
    explicit GC(void * impl): impl_(impl){};
  private:
    void* impl_;
  };

  class Event{
    friend NativeConverter;
  public:
    Event();
    ~Event();
    EventType type();
  private:
    void * impl_;
  };
  
  class Visual {
    friend NativeConverter;
  public:
    Visual();
  private:
        void* impl_;
  };
  
  
  class Display {
  public:
    Display(char* display_name);
    ~Display();
    DrawableId root_window( int screen_num);
    DrawableId create_simple_window(DrawableId parent,
				  int win_x, int win_y,
				  unsigned int width, unsigned int height,
				  unsigned int border_width,
				  unsigned long border,
				  unsigned long background);
    GC create_gc(DrawableId draw,const GCValues& values);
    void draw_point(DrawableId drawable, GC gc, int x, int y); 
    void draw_rectangle(DrawableId drawable, GC gc, int x, int y, unsigned int width, unsigned int height);
    void fill_rectangle(DrawableId drawable, GC gc, int x, int y,unsigned int width, unsigned int height);
    AtomId intern_atom(const std::string& atom_name, bool only_if_exists  );
    
    Status set_wm_protocols(DrawableId win, const std::vector<AtomId>& protocols  );
    void destroy_window(DrawableId win);
    void next_event(Event & event );
    void map_window(DrawableId);
    void select_input(DrawableId win, unsigned long mask);
    void flush();
    void sync(bool discard);
    int connection_number();
    int screen_count();
    int default_screen();
    unsigned long black_pixel(int);
    unsigned long white_pixel(int);
  private:
    using DisplayImpl = ::_XDisplay;
    DisplayImpl* impl; 
  };

}

#endif // X11WRAPPER_HPP
