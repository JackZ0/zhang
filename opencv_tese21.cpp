#include <iostream>    
#include <opencv2/highgui/highgui.hpp>    
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>    
#include <opencv2/ml/ml.hpp>    
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv/cv.h>
#include <Windows.h>  
  

#pragma comment( lib, "opencv_highgui249d.lib")
#pragma comment(lib,"opencv_imgproc249d.lib")  
#pragma comment(lib, "opencv_core249.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d.lib")   
#pragma comment(lib,"opencv_photo249d.lib")   
#pragma comment(lib,"opencv_nonfree249d.lib")   
#pragma comment(lib,"opencv_features2d249d.lib")   

using namespace std;    
using namespace cv;    

IplImage* pFrame = NULL;  
IplImage* pFrImg = NULL; 
IplImage* pBkImg = NULL; 
CvMat* pFrameMat = NULL; 
CvMat* pFrMat = NULL; 
CvMat* pBkMat = NULL; 
 
CvCapture* pCapture = NULL; 
 
int nFrmNum = 0; 
//创建窗口
int main()
{
	VideoCapture capture(0);  
    Mat frame, grayImage;  
  
    while (waitKey(30) != 27)  
    {  
        capture >> frame;  
  
        //canny边缘检测  
         cvtColor(frame, grayImage, CV_BGR2GRAY);  
         blur(grayImage, grayImage, Size(7, 7));  
		 //值越小，检测的细节越多
         Canny(grayImage, grayImage, 50, 50);  
  
        imshow("【摄像头】", grayImage);  
    }  
  
    return 0;  
}
