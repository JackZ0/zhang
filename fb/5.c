#include <stdbool.h>
#include <stdio.h>
#include <sys/mman.h>
#include<fcntl.h>
enum tag_DISP_CMD
{
    //----disp global----
    DISP_RESERVE0 = 0x00,
    DISP_RESERVE1 = 0x01,
    DISP_SET_BKCOLOR = 0x03,
    DISP_GET_BKCOLOR = 0x04,
    DISP_SET_COLORKEY = 0x05,
    DISP_GET_COLORKEY = 0x06,
    DISP_GET_SCN_WIDTH = 0x07,
    DISP_GET_SCN_HEIGHT = 0x08,
    DISP_GET_OUTPUT_TYPE = 0x09,
    DISP_SET_EXIT_MODE = 0x0A,
    DISP_VSYNC_EVENT_EN = 0x0B,
    DISP_BLANK = 0x0C,
    DISP_SHADOW_PROTECT = 0x0D,
    DISP_HWC_COMMIT = 0x0E,
    DISP_DEVICE_SWITCH = 0x0F,
    DISP_GET_OUTPUT = 0x10,
    DISP_SET_COLOR_RANGE = 0x11,
    DISP_GET_COLOR_RANGE = 0x12,
    DISP_HWC_CUSTOM = 0x13,

    //----layer----
    DISP_LAYER_ENABLE = 0x40,
    DISP_LAYER_DISABLE = 0x41,
    DISP_LAYER_SET_INFO = 0x42,
    DISP_LAYER_GET_INFO = 0x43,
    DISP_LAYER_TOP = 0x44,
    DISP_LAYER_BOTTOM = 0x45,
    DISP_LAYER_GET_FRAME_ID = 0x46,
    DISP_LAYER_SET_CONFIG = 0x47,
    DISP_LAYER_GET_CONFIG = 0x48,

    //----hdmi----
    DISP_HDMI_SUPPORT_MODE = 0xc4,
    DISP_SET_TV_HPD = 0xc5,
    DISP_HDMI_GET_EDID = 0xc6,

    //----lcd----
    DISP_LCD_ENABLE = 0x100,
    DISP_LCD_DISABLE = 0x101,
    DISP_LCD_SET_BRIGHTNESS = 0x102,
    DISP_LCD_GET_BRIGHTNESS = 0x103,
    DISP_LCD_BACKLIGHT_ENABLE  = 0x104,
    DISP_LCD_BACKLIGHT_DISABLE  = 0x105,
    DISP_LCD_SET_SRC = 0x106,
    DISP_LCD_SET_FPS  = 0x107,
    DISP_LCD_GET_FPS  = 0x108,
    DISP_LCD_GET_SIZE = 0x109,
    DISP_LCD_GET_MODEL_NAME = 0x10a,
    DISP_LCD_SET_GAMMA_TABLE = 0x10b,
    DISP_LCD_GAMMA_CORRECTION_ENABLE = 0x10c,
    DISP_LCD_GAMMA_CORRECTION_DISABLE = 0x10d,
    DISP_LCD_USER_DEFINED_FUNC = 0x10e,
    DISP_LCD_CHECK_OPEN_FINISH = 0x10f,
    DISP_LCD_CHECK_CLOSE_FINISH = 0x110,

    //---- capture ---
    DISP_CAPTURE_START = 0x140,//caputre screen and scaler to dram
    DISP_CAPTURE_STOP = 0x141,
    DISP_CAPTURE_COMMIT = 0x142,

    //---enhance ---
    DISP_ENHANCE_CONTRAST = 0x178,
    DISP_ENHANCE_SATUATION = 0x179,
    DISP_ENHANCE_ENABLE = 0x180,
    DISP_ENHANCE_DISABLE = 0x181,
    DISP_ENHANCE_GET_EN = 0x182,
    DISP_ENHANCE_SET_WINDOW = 0x183,
    DISP_ENHANCE_GET_WINDOW = 0x184,
    DISP_ENHANCE_SET_MODE = 0x185,
    DISP_ENHANCE_GET_MODE = 0x186,
    DISP_ENHANCE_DEMO_ENABLE = 0x187,
    DISP_ENHANCE_DEMO_DISABLE = 0x188,

    //---smart backlight ---
    DISP_SMBL_ENABLE = 0x200,
    DISP_SMBL_DISABLE = 0x201,
    DISP_SMBL_GET_EN = 0x202,
    DISP_SMBL_SET_WINDOW = 0x203,
    DISP_SMBL_GET_WINDOW = 0x204,

    //---- for test
    DISP_FB_REQUEST = 0x280,
    DISP_FB_RELEASE = 0x281,

    DISP_MEM_REQUEST = 0x2c0,
    DISP_MEM_RELEASE = 0x2c1,
    DISP_MEM_GETADR = 0x2c2,

    DISP_EINK_UPDATE  = 0x402,
    DISP_EINK_SET_TEMP = 0x403,
    DISP_EINK_GET_TEMP = 0x404,
};
enum disp_layer_mode
{
    LAYER_MODE_BUFFER = 0,
    LAYER_MODE_COLOR = 1,
};
struct disp_rect
{
    int x;
    int y;
    unsigned int width;
    unsigned int height;
};
enum disp_3d_out_mode
{
    DISP_3D_OUT_MODE_CI_1 = 0x5,//column interlaved 1
    DISP_3D_OUT_MODE_CI_2 = 0x6,//column interlaved 2
    DISP_3D_OUT_MODE_CI_3 = 0x7,//column interlaved 3
    DISP_3D_OUT_MODE_CI_4 = 0x8,//column interlaved 4
    DISP_3D_OUT_MODE_LIRGB = 0x9,//line interleaved rgb

    DISP_3D_OUT_MODE_TB = 0x0,//top bottom
    DISP_3D_OUT_MODE_FP = 0x1,//frame packing
    DISP_3D_OUT_MODE_SSF = 0x2,//side by side full
    DISP_3D_OUT_MODE_SSH = 0x3,//side by side half
    DISP_3D_OUT_MODE_LI = 0x4,//line interleaved
    DISP_3D_OUT_MODE_FA = 0xa,//field alternative
};

struct disp_rectsz
{
    unsigned int width;
    unsigned int height;
};
enum disp_pixel_format
{
    DISP_FORMAT_ARGB_8888                    = 0x00,//MSB  A-R-G-B  LSB
    DISP_FORMAT_ABGR_8888                    = 0x01,
    DISP_FORMAT_RGBA_8888                    = 0x02,
    DISP_FORMAT_BGRA_8888                    = 0x03,
    DISP_FORMAT_XRGB_8888                    = 0x04,
    DISP_FORMAT_XBGR_8888                    = 0x05,
    DISP_FORMAT_RGBX_8888                    = 0x06,
    DISP_FORMAT_BGRX_8888                    = 0x07,
    DISP_FORMAT_RGB_888                      = 0x08,
    DISP_FORMAT_BGR_888                      = 0x09,
    DISP_FORMAT_RGB_565                      = 0x0a,
    DISP_FORMAT_BGR_565                      = 0x0b,
    DISP_FORMAT_ARGB_4444                    = 0x0c,
    DISP_FORMAT_ABGR_4444                    = 0x0d,
    DISP_FORMAT_RGBA_4444                    = 0x0e,
    DISP_FORMAT_BGRA_4444                    = 0x0f,
    DISP_FORMAT_ARGB_1555                    = 0x10,
    DISP_FORMAT_ABGR_1555                    = 0x11,
    DISP_FORMAT_RGBA_5551                    = 0x12,
    DISP_FORMAT_BGRA_5551                    = 0x13,

    /* SP: semi-planar, P:planar, I:interleaved
     * UVUV: U in the LSBs;     VUVU: V in the LSBs */
    DISP_FORMAT_YUV444_I_AYUV                = 0x40,//MSB  A-Y-U-V  LSB, reserved
    DISP_FORMAT_YUV444_I_VUYA                = 0x41,//MSB  V-U-Y-A  LSB
    DISP_FORMAT_YUV422_I_YVYU                = 0x42,//MSB  Y-V-Y-U  LSB
    DISP_FORMAT_YUV422_I_YUYV                = 0x43,//MSB  Y-U-Y-V  LSB
    DISP_FORMAT_YUV422_I_UYVY                = 0x44,//MSB  U-Y-V-Y  LSB
    DISP_FORMAT_YUV422_I_VYUY                = 0x45,//MSB  V-Y-U-Y  LSB
    DISP_FORMAT_YUV444_P                     = 0x46,//MSB  P3-2-1-0 LSB,  YYYY UUUU VVVV, reserved
    DISP_FORMAT_YUV422_P                     = 0x47,//MSB  P3-2-1-0 LSB   YYYY UU   VV
    DISP_FORMAT_YUV420_P                     = 0x48,//MSB  P3-2-1-0 LSB   YYYY U    V
    DISP_FORMAT_YUV411_P                     = 0x49,//MSB  P3-2-1-0 LSB   YYYY U    V
    DISP_FORMAT_YUV422_SP_UVUV               = 0x4a,//MSB  V-U-V-U  LSB
    DISP_FORMAT_YUV422_SP_VUVU               = 0x4b,//MSB  U-V-U-V  LSB
    DISP_FORMAT_YUV420_SP_UVUV               = 0x4c,
    DISP_FORMAT_YUV420_SP_VUVU               = 0x4d,
    DISP_FORMAT_YUV411_SP_UVUV               = 0x4e,
    DISP_FORMAT_YUV411_SP_VUVU               = 0x4f,
    DISP_FORMAT_8BIT_GRAY				= 0x50,
};
enum disp_color_space
{
    DISP_BT601  = 0,
    DISP_BT709  = 1,
    DISP_YCC    = 2,
};
struct disp_rect64
{
    long long x;
    long long y;
    long long width;
    long long height;
};
enum disp_buffer_flags
{
    DISP_BF_NORMAL        = 0,//non-stereo
    DISP_BF_STEREO_TB     = 1 << 0,//stereo top-bottom
    DISP_BF_STEREO_FP     = 1 << 1,//stereo frame packing
    DISP_BF_STEREO_SSH    = 1 << 2,//stereo side by side half
    DISP_BF_STEREO_SSF    = 1 << 3,//stereo side by side full
    DISP_BF_STEREO_LI     = 1 << 4,//stereo line interlace
};
enum disp_scan_flags
{
    DISP_SCAN_PROGRESSIVE                 = 0,//non interlace
    DISP_SCAN_INTERLACED_ODD_FLD_FIRST    = 1 << 0,//interlace ,odd field first
    DISP_SCAN_INTERLACED_EVEN_FLD_FIRST   = 1 << 1,//interlace,even field first
};

struct disp_fb_info
{
    unsigned long long       addr[3];          /* address of frame buffer,single addr for interleaved fomart,double addr for semi-planar fomart triple addr for planar format */
    struct disp_rectsz       size[3];          //size for 3 component,unit: pixels
    unsigned int             align[3];         //align for 3 comonent,unit: bytes(align=2^n,i.e. 1/2/4/8/16/32..)
    enum disp_pixel_format   format;
    enum disp_color_space  color_space;      //color space
    unsigned int             trd_right_addr[3];/* right address of 3d fb,	used when in frame packing 3d mode */
    bool                     pre_multiply;     //true: pre-multiply fb
    struct disp_rect64       crop;             //crop rectangle boundaries
    enum disp_buffer_flags   flags;            //indicate stereo or non-stereo buffer
    enum disp_scan_flags     scan;             //scan type & scan order
};
struct disp_layer_info
{
    enum disp_layer_mode      mode;
    unsigned char             zorder;      /*specifies the front-to-back ordering of the layers on the screen,
                                             the top layer having the highest Z value
                                             can't set zorder, but can get */
    unsigned char             alpha_mode;  //0: pixel alpha;  1: global alpha;  2: global pixel alpha
    unsigned char             alpha_value; //global alpha value
    struct disp_rect          screen_win;  //display window on the screen
    bool                      b_trd_out;   //3d display
    enum disp_3d_out_mode     out_trd_mode;//3d display mode
    union {
        unsigned int            color;       //valid when LAYER_MODE_COLOR
        struct disp_fb_info     fb;          //framebuffer, valid when LAYER_MODE_BUFFER
    };

    unsigned int              id;          /* frame id, can get the id of frame display currently by DISP_LAYER_GET_FRAME_ID */
};
#define writel(val, addr) (*(((unsigned int *)(addr))) = (val)) 
//only for DISP_FORMAT_ARGB_8888 format 
int disp_draw_h_colorbar(unsigned int base, unsigned int width, unsigned int height) 
{ 
    unsigned int i=0, j=0; 

    for(i = 0; i<height; i++) { 
    for(j = 0; j<width/4; j++) {     
     unsigned int offset = 0; 
      
     offset = width * i + j; 
     writel((((1<<8)-1)<<24) | (((1<<8)-1)<<16), base + offset*4); 
      
     offset = width * i + j + width/4; 
     writel((((1<<8)-1)<<24) | (((1<<8)-1)<<8), base + offset*4); 
     offset = width * i + j + width/4; 
     writel((((1<<8)-1)<<24) | (((1<<8)-1)<<8), base + offset*4); 
      
     offset = width * i + j + width/4*2; 
     writel((((1<<8)-1)<<24) | (((1<<8)-1)<<0), base + offset*4); 
      
     offset = width * i + j + width/4*3; 
     writel((((1<<8)-1)<<24) | (((1<<8)-1)<<16) | (((1<<8)-1)<<8), base + offset*4); 
    } 
    }
    return 0; 
}
int main(int argc, char **argv) 
{ 
    unsigned int arg[3]; 
    struct disp_layer_info info; 
    unsigned int width = 1280; 
    unsigned int height = 800; 
    unsigned int ret = 0; 
    unsigned int screen_id = 0; 
    unsigned int layer_id = 0; 
    unsigned int mem_id = 0; 
    unsigned int buffer_num = 2; 
    unsigned int dispfh; 
    unsigned int fb_width,fb_height; 
    unsigned int mem, mem_phy; 

    if((dispfh = open("/dev/disp",O_RDWR)) == -1) { 
    printf("open display device fail!\n"); 
    return -1; 
    } 
 
    /* get screen size */ 
    arg[0] = screen_id; 
    width = ioctl(dispfh,DISP_GET_SCN_WIDTH,(void*)arg); 
    height = ioctl(dispfh,DISP_GET_SCN_HEIGHT,(void*)arg); 
    printf("screen_size=%d x %d \n", width, height); 

    fb_width = width; 
    fb_height = height; 
    /* request memory for layer */ 
    arg[0] = mem_id; 
    arg[1] = fb_width*fb_height*4*buffer_num; 
    arg[2] = 0; 
    arg[3] = 0; 
    if(ioctl(dispfh,DISP_MEM_REQUEST,(void*)arg) < 0) { 
    printf("DISP_MEM_REQUEST 0\n"); 
    close(dispfh); 
    return -1; 
    } 
 
    /* mmap memory requested */ 
    arg[0] = mem_id; 
    arg[1] = 0; 
    arg[2] = 0; 
    arg[3] = 0; 
    ioctl(dispfh,DISP_MEM_SELIDX,(void*)arg);
    mem = (int)mmap(NULL, fb_width*fb_height*4*buffer_num, PROT_READ | PROT_WRITE, MAP_SHARED, dispfh, 0L); 
    if(mem == 0) 
    { 
        printf("DISP_MEM_MAP 0\n"); 
        arg[0] = mem_id; 
        arg[1] = 0; 
        arg[2] = 0; 
        arg[3] = 0; 
        ioctl(dispfh,DISP_MEM_RELEASE,(void*)arg); 
        close(dispfh); 
        return -1; 
    }
    /* draw colorbar on the memory requested */ 
    memset((void*)mem, 0x0, fb_width*fb_height*4*buffer_num); 
    disp_draw_h_colorbar(mem, fb_width, fb_height); 
    munmap((void*)mem, fb_width*fb_height*4*buffer_num); 

    /* get physics address */ 
    arg[0] = mem_id; 
    mem_phy = ioctl(dispfh,DISP_MEM_GETADR,(void*)arg); 

    /* set layer info */ 
    memset(&info, 0, sizeof(struct disp_layer_info)); 
    info.mode             = DISP_LAYER_WORK_MODE_NORMAL; 
    info.fb.addr[0]       = (unsigned int)mem_phy; //FB地址 
    info.fb.size.width    = width; 
    info.fb.format        = DISP_FORMAT_ARGB_8888; //DISP_FORMAT_YUV420_P 
    info.fb.src_win.x     = 0; 
    info.fb.src_win.y     = 0; 
    info.fb.src_win.width = width; 
    info.fb.src_win.height= height; 
    info.ck_enable        = 0; 
    info.alpha_mode       = 1; //global alpha 
    info.alpha_value      = 0xff; 
    info.pipe             = 1;   
    info.screen_win.x     = 0; 
    info.screen_win.y     = 0; 
    info.screen_win.width = width; 
    info.screen_win.height= height; 
    info.id               = 0; 
    arg[0] = screen_id;//显示通道 0 
    arg[1] = layer_id;//图层 0 
    arg[2] = (unsigned int)&info; 
    ret = ioctl(dispfh, DISP_LAYER_SET_INFO, (void*)arg); 
    if(0 != ret) 
    printf("fail to set layer info\n"); 

    /* enable layer */ 
    arg[0] = screen_id; 
    arg[1] = layer_id; 
    arg[2] = 0; 
    arg[3] = 0; 
    ret = ioctl(dispfh,DISP_LAYER_ENABLE,(void*)arg); 
    if(0 != ret) 
    printf("fail to enable layer\n"); 

    sleep(5); 

    /* clear resource */ 
    arg[0] = screen_id; 
    arg[1] = layer_id; 
    arg[2] = 0; 
    arg[3] = 0; 
    ret = ioctl(dispfh,DISP_LAYER_DISABLE,(void*)arg); 
    if(0 != ret) 
    printf("fail to enable layer\n"); 

    memset(&info, 0, sizeof(disp_layer_info)); 
    arg[0] = screen_id; 
    arg[1] = layer_id; 
    arg[2] = (unsigned int)&info; 
    ret = ioctl(dispfh, DISP_LAYER_SET_INFO, (void*)arg); 
    arg[0] = mem_id; 
    ioctl(dispfh,DISP_MEM_RELEASE,(void*)arg); 

    close(dispfh); 
    return 0; 
}  
