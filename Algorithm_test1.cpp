
#include <string.h>  
#include <afx.h>
#include <fstream>
#include <iostream>
#include <vector>  
#include <cmath>
#include <math.h>
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

int p[32*32]={0};
#define funcpower(a) ((a)*(a))
int main(int argc, char* argv[])  
{  
	
	IplImage *img=cvLoadImage("1.jpg",1);
	for(int i=0; i < img->height;i++)
	{
		for(int j=0; j< img->width;j++)
		{
			int bVal=((uchar*)(img->imageData+i*img->widthStep))[j*img->nChannels+0];
			int gVal=((uchar *)(img->imageData+i*img->widthStep))[j*img->nChannels+1];
			int rVal=((uchar *)(img->imageData+i*img->widthStep))[j*img->nChannels+2];
			//printf("bVal = %d gVal = %d rVal = %d\n",bVal,gVal,rVal);
			p[i*img->width+j]=sqrt((double)funcpower(bVal)+funcpower(gVal)+funcpower(rVal));
			printf("%d \n",p[i*img->width+j]);
		}
	}
    while(1);
}  
