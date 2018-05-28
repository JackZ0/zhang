#include <string.h>  
#include <afx.h>
#include <fstream>
#include <iostream>
#include <vector>  
#include <time.h>
#pragma comment(lib,"Wininet.lib")  

#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/contrib/contrib.hpp>
#include "opencv2/video/video.hpp"
#include "opencv2/videostab/videostab.hpp"
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/features2d/features2d.hpp>
#include<opencv2/nonfree/features2d.hpp>
#include<opencv2/legacy/legacy.hpp>
#include <opencv/cxcore.h>
#include <opencv/cv.h>

#pragma comment( lib, "opencv_highgui249d.lib")
#pragma comment(lib,"opencv_imgproc249d.lib")  
#pragma comment(lib, "opencv_core249.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d.lib")   
#pragma comment(lib,"opencv_photo249d.lib")   
#pragma comment(lib,"opencv_nonfree249d.lib")   
#pragma comment(lib,"opencv_features2d249d.lib")   

  
using namespace cv;  
using namespace std;

#define max_corners 10000 
int main()
{
	int cornerCount=max_corners;
	CvPoint2D32f corners[max_corners]; 
    IplImage *srcImage = 0, *grayImage = 0, *corners1 = 0, *corners2 = 0; 
	int i; 
    CvScalar color = CV_RGB(255,0,0); 
    char* filename ="5.jpg";  
	cvNamedWindow("image",1);
	srcImage = cvLoadImage(filename,1);
	grayImage = cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_8U,1);
	cvCvtColor(srcImage,grayImage,CV_BGR2GRAY);
	corners1= cvCreateImage(cvGetSize(srcImage), IPL_DEPTH_32F, 1); 
    corners2= cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_32F, 1); 
	cvGoodFeaturesToTrack (grayImage, corners1,corners2, corners, &cornerCount, 0.05, 
        5,  
        0, 
        3, // block size 
        0, // not use harris 
        0.4 ); 
	printf("num corners found: %d\n", cornerCount);
	if(cornerCount>0)  
    { 
        for (i=0; i<cornerCount; i++)  
        { 
            cvCircle(srcImage, cvPoint((int)(corners[i].x), (int)(corners[i].y)), 6, color, 2, CV_AA, 0); \
		}
	 }
	 cvShowImage( "image", srcImage );  
     
   /* cvReleaseImage(&srcImage); 
    cvReleaseImage(&grayImage); 
    cvReleaseImage(&corners1); 
    cvReleaseImage(&corners2); */
     
    cvWaitKey(0); // wait for key. The function has 
    return 0; 

}
