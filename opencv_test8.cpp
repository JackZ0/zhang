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
#include<opencv2/features2d/features2d.hpp>
#include<opencv2/nonfree/features2d.hpp>
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
#pragma comment(lib,"opencv_objdetect249d.lib")   
#pragma comment(lib,"opencv_photo249d.lib")   
#pragma comment(lib,"opencv_nonfree249d.lib")   
#pragma comment(lib,"opencv_features2d249d.lib")   

  
using namespace cv;  
using namespace std;

#define MAX_CORNERS 100  
   
int main()
{
    // 读入图像, 第二个参数0表示灰度图
    Mat image = imread("1.png");
    Mat featureImage;

    cv::namedWindow("Original Image");
    cv::imshow("Original Image", image);

    // 特征点的向量
    std::vector<cv::KeyPoint> keypoints;

    // 构造SIFT特征检测器
    cv::SiftFeatureDetector sift; 

    // 检测SIFT特征值
    sift.detect(image, keypoints);

    drawKeypoints(image,         // 原始图像
                  keypoints, // 特征点的向量
                  featureImage, // 生成图像
                  cv::Scalar(255,255,255), // 特征点的颜色
                  cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS); // 标志位

    cv::namedWindow("SIFT Features");
    cv::imshow("SIFT Features", featureImage);

    cv::waitKey(0);
    return 0;
}
