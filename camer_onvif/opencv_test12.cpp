#include<iostream>  
#include <opencv/cv.hpp>
#include <opencv/highgui.h>
//#include "imgproc.hpp"    
using namespace std;  
using namespace cv;  
#define kernel 10  
int main()  
{  
    Mat dst, src = imread("1.jpg");//读入图片  
    imshow("SRC",src);             //显示原图  
      
    Mat element = getStructuringElement(MORPH_RECT, Size(kernel, kernel));//设置内核参数  
  
    //7种形态学滤波类型  
    morphologyEx(src,dst,MORPH_ERODE,element);          imshow("ERRODE", dst);    //膨胀  
    morphologyEx(src, dst, MORPH_DILATE, element);      imshow("DILATE", dst);    //腐蚀  
    morphologyEx(src, dst, MORPH_OPEN, element);        imshow("OPEN", dst);      //开运算  
    morphologyEx(src, dst, MORPH_CLOSE, element);       imshow("CLOSE", dst);     //闭运算  
    morphologyEx(src, dst, MORPH_GRADIENT, element);    imshow("GRADIENT", dst);  //形态学梯度  
    morphologyEx(src, dst, MORPH_TOPHAT, element);      imshow("TOPHAT", dst);    //顶帽  
    morphologyEx(src, dst, MORPH_BLACKHAT, element);    imshow("BLACKHaT", dst);  //黑帽  
  
  
    waitKey(); //等待  
    return 0;  
}  
