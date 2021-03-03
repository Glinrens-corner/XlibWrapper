#ifndef X11WRAPPER_HPP
#define X11WRAPPER_HPP
#include <memory>
struct _XGC;
struct _XDisplay;
namespace x11 {
  using DrawableId = unsigned long;
  struct NativeConverter;
  
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
    KeyPressType,
    KeyReleaseType,
    ButtonPressType,
    ButtonReleaseType,
    MotionNotifyType,
    EnterNotifyType,
    LeaveNotifyType,
    FocusInType,
    FocusOutType,
    KeymapNotifyType,
    ExposeType,
    GraphicsExposeType,
    NoExposeType,
    CirculateRequestType,
    ConfigureRequestType,
    MapRequestType,
    ResizeRequestType,
    CirculateNotifyType,
    ConfigureNotifyType,
    CreateNotifyType,
    DestroyNotifyType,
    GravityNotifyType,
    MapNotifyType,
    MappingNotifyType,
    ReparentNotifyType,
    UnmapNotifyType,
    VisibilityNotifyType,
    ColormapNotifyType,
    ClientMessageType,
    PropertyNotifyType,
    SelectionClearType,
    SelectionNotifyType,
    SelectionRequestType,
    UnknownType
  };
 
					
  
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
    void next_event(Event & event );
    void map_window(DrawableId);
    void select_input(DrawableId win);
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
