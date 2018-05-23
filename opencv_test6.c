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

int main()
{
  IplImage* pCannyImg = NULL;  
    IplImage* pImg = NULL;  
   Mat img = imread("2.png",1);     
 // Mat img = imread("image.jpg");    
Mat grey;    
cvtColor(img, grey, CV_BGR2GRAY);    
  
Mat sobelx;    
Sobel(grey, sobelx, CV_32F, 1, 0);    
  
double minVal, maxVal;    
minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities    
Mat draw;    
sobelx.convertTo(draw, CV_8U, 255.0/(maxVal - minVal), -minVal * 255.0/(maxVal - minVal));    
  
namedWindow("1", CV_WINDOW_AUTOSIZE);    
imshow("1",img);   
imshow("",draw);    
  
//*pImg = IplImage(draw);  
  
//pCannyImg = cvCreateImage(cvGetSize(&draw), IPL_DEPTH_8U, 1);  
//cvCanny(&draw, pCannyImg, 100, 180, 3);  
//cvNamedWindow("canny",1);  
//cvShowImage( "canny", pCannyImg );  
waitKey();    
      
   return 0;     
}
