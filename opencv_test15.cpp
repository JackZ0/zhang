#include <iostream>    
#include <opencv2/highgui/highgui.hpp>    
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>    
#include <opencv2/ml/ml.hpp>    
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/features2d/features2d.hpp>
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
  

int main( int argc, char** argv )
{
	Mat image=imread("1.jpg");
	cv::namedWindow("Original Image");
    cv::imshow("Original Image", image);


    // 特征点的向量
    std::vector<cv::KeyPoint> keypoints;

    // 构造SURF特征检测器
    cv::SurfFeatureDetector surf;

    // 检测SURF特征
    surf.detect(image, keypoints);

    cv::Mat featureImage;

    cv::drawKeypoints(image,         // 原始图像
                      keypoints,     // 特征点的向量
                      featureImage,  // 生成图像
                      cv::Scalar(255,255,255), // 特征点的颜色
                      cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS); // 标志位

    cv::namedWindow("SURF Features");
    cv::imshow("SURF Features",featureImage);

    cv::waitKey(0);

    return 0;
}    
