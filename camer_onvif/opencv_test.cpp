
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
int main()
{
	cv::VideoCapture vcap;  
    cv::Mat image;  
  
    // This works on a D-Link CDS-932L  
    //const std::string videoStreamAddress = "http://<username:password>@<ip_address>/video.cgi?.mjpg";  
    const std::string videoStreamAddress = "rtsp://admin:User1234@192.168.1.168/h264/ch1/main/av_stream";  
    //open the video stream and make sure it's opened  
    if(!vcap.open(videoStreamAddress)) {  
        std::cout << "Error opening video stream or file" << std::endl;  
        return -1;  
    }  
  
    for(;;) {  
        if(!vcap.read(image)) {  
            std::cout << "No frame" << std::endl;  
            cv::waitKey();  
        }   
        cv::imshow("Output Window", image);  
        if(cv::waitKey(1) >= 0) {  
            break;  
        }  
    }     
}
