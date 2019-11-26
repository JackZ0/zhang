#include "stdafx.h"
#include <iostream>
#include <string.h>
#include<opencv2\opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
 
	Mat src = imread("images/2.jpg");//图片必须添加到工程目录下
 
	// 将原图像转换为灰度图像    
	//cvtColor(src, src, CV_BGR2GRAY)
 
	//在原图画一个圆圈点
	cv::Point point;//特征点，用以画在图像中  
	point.x = 20;//特征点在图像中横坐标  
	point.y = 50;//特征点在图像中纵坐标  
	cv::circle(src, point, 4, cv::Scalar(0, 0, 255));//在图像中画出特征点，2是圆的半径 
 
	//在原图画一条直线
	cv::Point start = cv::Point(10, 100); //直线起点
	cv::Point end = cv::Point(50, 200);   //直线终点
	cv::line(src, start, end, cv::Scalar(0, 0, 255));
 
	//在原图某个位置添加文字标记
	//char str[4];
	//int num = 100;
	//_itoa_s(num, str, 10);//数字需要转为字符串来显示
	string str = "Love100";
	putText(src, str, end, cv::FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(0, 255,0 ), 2);
	imshow("src", src);
	waitKey(0);
}
