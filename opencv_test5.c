#include <windows.h>  
#include <mmsystem.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include "wininet.h"  
#include <direct.h>  
#include <string.h>  
#include <list>  

#pragma comment(lib,"Wininet.lib")  

#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/contrib/contrib.hpp>
#include "opencv2/video/video.hpp"
#include "opencv2/videostab/videostab.hpp"
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv/cxcore.h>
#include <opencv/cv.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#pragma comment( lib, "opencv_highgui249d.lib")
#pragma comment(lib,"opencv_imgproc249d.lib")  
#pragma comment(lib, "opencv_core249.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d")   
  
using namespace cv;  
using namespace std;

int main( int argc, char** argv )  
{  
         //声明IplImage指针  
         IplImage* pImg = NULL;  
         IplImage* pCannyImg = NULL;  
         //载入图像，强制转化为Gray  
         pImg = cvLoadImage( "1.png",0);  
         //为canny边缘图像申请空间  
         //IplImage* cvCreateImage( CvSize size, int depth, int channels );  
         pCannyImg = cvCreateImage(cvGetSize(pImg), IPL_DEPTH_8U, 1);  
         //canny边缘检测  
         //第一个参数image 输入单通道图像（可以是彩色图像）对于多通道的图像可以用cvCvtColor()修改。  
         //第三个参数是控制细节的，越小细节越多，  
         cvCanny(pImg, pCannyImg, 50, 150, 3);  
         //创建窗口  
         //0表示用户可以手动调节窗口大小，且显示的图像尺寸随之变化。  
         cvNamedWindow("src", 1);  
         cvNamedWindow("canny",1);  
         //显示图像  
         cvShowImage( "src", pImg );  
         cvShowImage( "canny", pCannyImg );  
         //等待按键  
         cvWaitKey(0);  
         //销毁窗口  
         cvDestroyWindow( "src" );  
         cvDestroyWindow( "canny" );  
         //释放图像  
         cvReleaseImage( &pImg );  
         cvReleaseImage( &pCannyImg );  
         return 0;  
} 
