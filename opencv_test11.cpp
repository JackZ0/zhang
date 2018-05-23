
#include <string.h>  
#include <afx.h>
#include <iostream>
#include <vector>  
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

int main()
{
     Mat srcImage=imread("1.jpg");  
    Mat temImage,dstImage1,dstImage2;  
    temImage=srcImage;  
  
    //显示原图  
    imshow("原图",srcImage);  
  
    //尺寸调整  
    resize(temImage,dstImage1,Size(temImage.cols/2,temImage.rows/2),0,0,INTER_LINEAR);  
    resize(temImage,dstImage2,Size(temImage.cols*2,temImage.rows*2),0,0,INTER_LINEAR);  
  
    imshow("缩小",dstImage1);  
    imshow("放大",dstImage2);  
  
    waitKey();  
    return 0;  
}
