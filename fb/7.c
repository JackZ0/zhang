#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "sunxi_display2.h"

#define writel(val, addr) (*(((unsigned int *)(addr))) = (val)) 

int disp_draw_h_colorbar(unsigned int base, unsigned int width, unsigned int height) 
{ 
    unsigned int i=0, j=0; 
    for(i = 0; i<height; i++)
    {
        for(j = 0; j<width/4; j++) 
	{     
            unsigned int offset = 0; 
   
            offset = width * i + j; 
            writel((((1<<8)-1)<<24) | (((1<<8)-1)<<16), base + offset*4); 
   
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
//    disp_layer_info info; 
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
     
     if((dispfh = open("/dev/disp",O_RDWR)) == -1) 
     { 
         printf("open display device fail!\n"); 
         return -1; 
     }


     arg[0] = screen_id; 
     width = ioctl(dispfh,DISP_GET_SCN_WIDTH,(void*)arg); 
     height = ioctl(dispfh,DISP_GET_SCN_HEIGHT,(void*)arg); 
     printf("screen_size=%d x %d \n", width, height); 
    
     fb_width = width; 
     fb_height = height; 
     arg[0] = mem_id; 
     arg[1] = fb_width*fb_height*4*buffer_num; 
     arg[2] = 0; 
     arg[3] = 0; 
     if(ioctl(dispfh,DISP_MEM_REQUEST,(void*)arg) < 0)
     { 
  	 printf("DISP_MEM_REQUEST 0\n"); 
	 close(dispfh); 
	 return -1; 
     } 
     arg[0] = mem_id; 
     arg[1] = 0; 
     arg[2] = 0; 
     arg[3] = 0; 
    ioctl(dispfh,DISP_MEM_GETADR,(void*)arg); 
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
     memset((void*)mem, 0x0, fb_width*fb_height*4*buffer_num); 

     disp_draw_h_colorbar(mem, fb_width, fb_height); 

     munmap((void*)mem, fb_width*fb_height*4*buffer_num); 
     arg[0] = mem_id; 
     mem_phy = ioctl(dispfh,DISP_MEM_GETADR,(void*)arg); 
     memset(&info, 0, sizeof(struct disp_layer_info)); 
     info.mode             = LAYER_MODE_BUFFER; 
     info.fb.addr[0]       = (__u32)mem_phy; //FB地址 
     info.fb.size->width    = width; 
     info.fb.format        = DISP_FORMAT_ARGB_8888; //DISP_FORMAT_YUV420_P 
     info.fb.crop.x     = 0; 
     info.fb.crop.y     = 0; 
     info.fb.crop.width = width; 
     info.fb.crop.height= height; 
//   info.ck_enable        = 0; 
     info.alpha_mode       = 1; //global alpha 
     info.alpha_value      = 0xff; 
//    info.pipe             = 1;   
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

    arg[0] = screen_id; 
    arg[1] = layer_id; 
    arg[2] = 0; 
    arg[3] = 0; 
    ret = ioctl(dispfh,DISP_LAYER_DISABLE,(void*)arg); 
    if(0 != ret) 
    printf("fail to enable layer\n"); 
 
    memset(&info, 0, sizeof(struct disp_layer_info)); 
    arg[0] = screen_id; 
    arg[1] = layer_id; 
    arg[2] = (unsigned int)&info; 
    ret = ioctl(dispfh, DISP_LAYER_SET_INFO, (void*)arg); 
    arg[0] = mem_id; 
    ioctl(dispfh,DISP_MEM_RELEASE,(void*)arg); 

    close(dispfh); 
    return 0; 
}

