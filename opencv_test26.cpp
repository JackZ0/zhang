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
  

int main()
{
	//打开第一个摄像头  
    VideoCapture cap(0);  
    //检查摄像头是否成功打开  
    if (!cap.isOpened())  
    {  
        cout<<"摄像头未成功打开"<<endl;  
    }  
    //创建Mat对象  
    Mat M;  
    //创建窗口  
    namedWindow("打开摄像头",1);  
    //读取摄像头中的帧  
    for (;;)  
    {  
        Mat frame; 
        //从cap中读取一帧存到frame中  
        cap>>frame;  
        //判断是否读取到  
        if (frame.empty())  
        {  
            break;  
        }  
        //将摄像头读取到的图像转化为灰度图  
        cvtColor(frame,M,CV_BGR2GRAY);  
        //进行canny算子边缘化提取  
        Canny(M,M,0,30,3);  
        //在窗口中显示视频中每一帧被边缘化的图像  
        imshow("打开摄像头",M);  
        //等待300秒，如果按键则退出循环  
        if (waitKey(300)>=0)  
        {  
            break;  
        }  
    }  
}    
