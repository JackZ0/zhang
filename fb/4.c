//SDKLIB_TEST have already defined by Makefile
#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <linux/fb.h>

#include "hwdisp2.h"
#include "aw_ini_parser.h"
#include "sdklog.h"
#include "CameraDebug.h"
#include "hwdisp2.h"

//#include "V4L2CameraDevice2.h"
//#include "CallbackNotifier.h"
//#include "PreviewWindow.h"
//#include "CameraHardware2.h"
//#include "HALCameraFactory.h"
//#include "CameraHardwareInterface.h"
//#include "audio_hal.h"
//#include "awrecorder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <sys/time.h>
//#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "vencoder.h"
#include "CdxMuxer.h"
#include <time.h>

//#include "Rtc.h"
//#include "StorageManager.h"
//#include "DvrFactory.h"
//#include "CameraFileCfg.h"
#include <sys/socket.h>
#include <sys/un.h>
//#include "Fat.h"
//#include "DebugLevelThread.h"
//#include "DvrRecordManager.h"
using namespace android;
int g_recordstatus=0;
//#define DB_LEVEL_TEST
//#define FORMATE_TEST

int video_layer0;
void ShowYUVpictureDemo(HwDisplay* mcd);


#define PATH_SDCARD  "/mnt/sdcard/mmcblk1p1/"
#define PATH_SD_DEV  "/dev/mmcblk1p1"
#define LOG_BUF_SIZE    1024
static int sdkloglevel=3;
int sdk_log_setlevel(int prio)
{
        if((prio > 6)||(prio <0))
        {
                prio = 6;
        }
        printf("set sdk log level %d \r\n",prio);
        sdkloglevel=prio;
}

int sdk_log_print(int prio, const char *tag,const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];
        if(prio>=sdkloglevel)
                return 0;

#if defined(HAVE_LOCALTIME_R)    
        struct tm tmBuf;
#endif
        struct tm* ptm;

 //time_t timep;
 //     time(&timep);

    struct timeval tv;
    //struct timezone tz;

    gettimeofday (&tv, NULL);

#if defined(HAVE_LOCALTIME_R)    
        ptm = localtime_r(&(tv.tv_sec), &tmBuf);
#else
        ptm = localtime(&(tv.tv_sec));
#endif
char timeBuf[32];
strftime(timeBuf, sizeof(timeBuf), "%m-%d %H:%M:%S", ptm);

int nm=snprintf(buf,LOG_BUF_SIZE,"%s.%03ld  %s", timeBuf, tv.tv_usec / 1000,tag);

        int slen=strlen(buf);
        buf[slen]='\r';
        buf[slen+1]='\n';
        buf[slen+2]=0;
    return printf(buf);
}

int main(int argc,char *argv[])
{
    int i=1;
    int rt ;
	int flag360=0;
	char *name;
    HwDisplay* mcd=NULL;
	int tvmode=3; //0 disable ,1 tvout pal ;2 tvout ntsc;3 hdmi 1280x720;4 hdmi 1920x1080 
	printf("--------------argc =%d \r\n",argc);
	if(argc >1)
	{
		if(strstr(argv[1],"360")){
			flag360=1;
		}else {
			name=argv[1];
		}
		printf("------------argv =%s \r\n",argv[1]);
	}else
	{
		name="0";
	}	
	//config_set_tvout(TEST_CAMERA_ID,tvmode);
	sdk_log_setlevel(3);
    mcd=HwDisplay::getInstance();
	ShowYUVpictureDemo(mcd);
	


    return 0;
}


void ShowYUVpictureDemo(HwDisplay* mcd)
{
	ALOGD("AUT_LAYER_TEST begin \r\n");
	struct ScMemOpsS* dispmemops = MemAdapterGetOpsS();	 
	
	int ret = CdcMemOpen(dispmemops);

	if (ret < 0)
	{
		ALOGE("ion_alloc_open failed");
		return ;
	}
	int disp_vaddr= (int)CdcMemPalloc(dispmemops, 1920*1080*4);
	int disp_paddr=(int)CdcMemGetPhysicAddressCpu(dispmemops,(void*)disp_vaddr);

	FILE *fpff = fopen("./1.argb","rb");
	if(NULL == fpff){
		fpff = fopen("/mnt/usb/sda1/100.yuv","rb");
		if(NULL == fpff){
			ALOGE("fopen 100.YUV ERR \r\n");
		}
		else{
			ALOGD("fopen 100.YUV OK \r\n");
			fread((void *)disp_vaddr, 1, 1920*1080*4, fpff);
			fclose(fpff);
		}
	}
	else{
		ALOGD("fopen 100.YUV OK \r\n");
		fread((void *)disp_vaddr, 1, 1920*1080*4, fpff);
		fclose(fpff);
	}
	
	struct view_info surface0={0,0,1920,1080};
	struct src_info src={1920,1080,DISP_FORMAT_ARGB_8888};
	ALOGD("layer_request  layer0 \r\n");
	video_layer0=mcd->aut_hwd_layer_request(&surface0,1,0,0);
	
	mcd->aut_hwd_layer_set_src(video_layer0,&src,(int)&disp_paddr);
	mcd->aut_hwd_layer_set_zorder(video_layer0,4);
	mcd->aut_hwd_layer_open(video_layer0);
	
	mcd->aut_hwd_layer_render(video_layer0, (void *)&disp_paddr,0);
	ALOGD("aut_hwd_layer_render video_layer0");
	sleep(2000);
	CdcMemPfree(dispmemops, (void *)disp_vaddr);
	CdcMemClose(dispmemops);
	while(1);

}
