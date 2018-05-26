
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
	 cv::Mat image_bak;
	 vector<Rect> personSVM, personCasc,personListSVM, personListCacs;//检测结果矩形框向量  
	 DWORD SVMTimeBegin,SVMTimeEnd,CascTimeBegin,CascTimeEnd;  //耗时统计   
 //   // This works on a D-Link CDS-932L  
      //const std::string videoStreamAddress = "http://<username:password>@<ip_address>/video.cgi?.mjpg";  
     const std::string videoStreamAddress = "rtsp://admin:User1234@192.168.1.168/h264/ch1/main/av_stream";  
	//  const std::string videoStreamAddress = "rtmp://live.hkstv.hk.lxdns.com/live/hks";  
	 //  const std::string videoStreamAddress = "http://live.hkstv.hk.lxdns.com/live/hks/playlist.m3u8";  
     //open the video stream and make sure it's opened  
		if(!vcap.open(videoStreamAddress)) 
		{  
			std::cout << "Error opening video stream or file" << std::endl;  
			return -1;  
		} 
     
     for(;;) 
	 {  
		
        if(!vcap.read(image_bak)) 
		{  
	         std::cout << "No frame" << std::endl;  
             cv::waitKey();  
        }   
	// 	cvtColor(image, image_gray, CV_BGR2GRAY);//转为灰度图
	//	equalizeHist(image_gray, image_gray);//直方图均衡化，增加对比度方便处理 
		image=image_bak.clone();
		CascTimeBegin=GetTickCount();    
       
		CascadeClassifier face_cascade;    //载入分类器
		if (!face_cascade.load("C://opencv//sources//data//hogcascades//hogcascade_pedestrians.xml"))
		{
			cout << "Load haarcascade_frontalface_alt failed!" << endl;
			return 0;
		}
		//vector 是个类模板 需要提供明确的模板实参 vector<Rect>则是个确定的类 模板的实例化
		//vector<Rect> faceRect;
		//检测关于脸部位置
		face_cascade.detectMultiScale(image_bak, personCasc); 
		
		for(int i=0; i < personSVM.size(); i++)    
		{    
			Rect r = personSVM[i];    
			int j=0;    
			for(; j < personSVM.size(); j++)    
				if(j != i && (r & personSVM[j]) == r)    
					break;    
			if( j == personSVM.size())    
				personListSVM.push_back(r);    
		}    
		for(int i=0; i < personCasc.size(); i++)    
		{    
			Rect r = personCasc[i];    
			int j=0;    
			for(; j < personCasc.size(); j++)    
				if(j != i && (r & personCasc[j]) == r)    
					break;    
			if( j == personCasc.size())    
				personListCacs.push_back(r);    
		}    
		
		//画矩形框，缩放检测到的矩形框   
		for(int i=0; i<personListSVM.size(); i++)    
		{    
			Rect r = personListSVM[i];    
			r.x += cvRound(r.width*0.1);    
			r.width = cvRound(r.width*0.8);    
			r.y += cvRound(r.height*0.07);    
			r.height = cvRound(r.height*0.8);    
			rectangle(image_bak, r.tl(), r.br(), Scalar(0,0,255), 2);    
		}    
		for(int i=0; i<personListCacs.size(); i++)    
		{    
			Rect r = personListCacs[i];    
			r.x += cvRound(r.width*0.1);    
			r.width = cvRound(r.width*0.8);    
			r.y += cvRound(r.height*0.07);    
			r.height = cvRound(r.height*0.8);    
			rectangle(image_bak, r.tl(), r.br(), Scalar(0,0,255), 2);    
		}    

		CascTimeEnd=GetTickCount();   
        cout<<"HOG+Cascade行人检测耗时：\n"<<(CascTimeEnd-CascTimeBegin)<<endl;  

		imshow("行人检测",image_bak);    
		image.release();
		if(cv::waitKey(1) >= 0) 
		{  
			break;  
		}  
	}     
	return 0;
}
