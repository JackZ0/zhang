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
	VideoCapture capture;
	capture.open("1.wmv");
	Mat Frame;
	while(1)
	{
		
		capture>>Frame;
		imshow("读取视频",Frame);
		waitKey(30);
	}
	

	return 0;
}    
