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
	Mat srcImage=imread("1.jpg");
	imshow("原图",srcImage);
	Mat dstImage;
	Mat edge;
	Mat grayImage;

	dstImage.create(srcImage.size(),srcImage.type());


	cvtColor(srcImage,grayImage,CV_BGR2GRAY);
	//3*3降噪处理
	blur(srcImage,edge,Size(3,3));
	Canny(edge,dstImage,3,9,3);
	imshow("Canny 边缘检测",dstImage);

	waitKey(0);

	return 0;
}    
