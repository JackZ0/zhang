#include <opencv2/core/core.hpp>  
#include <opencv2/features2d/features2d.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <iostream>
#include <vector>  


#pragma comment( lib, "opencv_highgui249d.lib")
#pragma comment(lib,"opencv_imgproc249d.lib")  
#pragma comment(lib, "opencv_core249.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d")  
#pragma comment(lib,"opencv_nonfree249d.lib")
#pragma comment(lib,"opencv_legacy249d.lib")
#pragma comment(lib,"opencv_features2d249d.lib")

using namespace cv; 
using namespace std;
  
void main()  
{  
    Mat image;  
    image = imread("church01.jpg");  
    // vector of keyPoints  
    std::vector<KeyPoint> keyPoints;  
    // construction of the fast feature detector object  
    FastFeatureDetector fast(40);   // 检测的阈值为40  
    // feature point detection  
    fast.detect(image,keyPoints);  
    drawKeypoints(image, keyPoints, image, Scalar::all(255), DrawMatchesFlags::DRAW_OVER_OUTIMG);  
    imshow("FAST feature", image);  
    cvWaitKey(0);  
}  
