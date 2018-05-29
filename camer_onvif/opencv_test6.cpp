#include <string.h>  
#include <afx.h>
#include <fstream>
#include <iostream>
#include <vector>  
//#include <time.h>
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
#pragma comment(lib, "opencv_core249d.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d.lib")   
#pragma comment(lib,"opencv_photo249d.lib")   
#pragma comment(lib,"opencv_nonfree249d.lib")   
#pragma comment(lib,"opencv_features2d249d.lib")   
//#pragma comment(linker,"/subsystem:windows /ENTRY:mainCRTStartup")

using namespace cv;  
using namespace std;
using std::vector;
int HistogramBins = 256;  
float HistogramRange1[2]={0,255};  
float *HistogramRange[1]={&HistogramRange1[0]};  
int CompareHist(const char* imagefile1, const char* imagefile2)  
{  
    IplImage *image1=cvLoadImage(imagefile1, 0);  
    IplImage *image2=cvLoadImage(imagefile2, 0);  
  
    CvHistogram *Histogram1 = cvCreateHist(1, &HistogramBins, CV_HIST_ARRAY,HistogramRange);  
    CvHistogram *Histogram2 = cvCreateHist(1, &HistogramBins, CV_HIST_ARRAY,HistogramRange);  
  
    cvCalcHist(&image1, Histogram1);  
    cvCalcHist(&image2, Histogram2);  
  
    cvNormalizeHist(Histogram1, 1);  
    cvNormalizeHist(Histogram2, 1);  
  
    // CV_COMP_CHISQR,CV_COMP_BHATTACHARYYA这两种都可以用来做直方图的比较，值越小，说明图形越相似  
    printf("CV_COMP_CHISQR : %.4f\n", cvCompareHist(Histogram1, Histogram2, CV_COMP_CHISQR));  
    printf("CV_COMP_BHATTACHARYYA : %.4f\n", cvCompareHist(Histogram1, Histogram2, CV_COMP_BHATTACHARYYA));  
  
  
    // CV_COMP_CORREL, CV_COMP_INTERSECT这两种直方图的比较，值越大，说明图形越相似  
    printf("CV_COMP_CORREL : %.4f\n", cvCompareHist(Histogram1, Histogram2, CV_COMP_CORREL));  
    printf("CV_COMP_INTERSECT : %.4f\n", cvCompareHist(Histogram1, Histogram2, CV_COMP_INTERSECT));  
  
    cvReleaseImage(&image1);  
    cvReleaseImage(&image2);  
    cvReleaseHist(&Histogram1);  
    cvReleaseHist(&Histogram2);  
    return 0;  
}  
int main()
{
	CompareHist("5.jpg", "3.jpg");  
    //CompareHist("d:\\camera.jpg", "d:\\camera1.jpg");  
    return 0;  
}
