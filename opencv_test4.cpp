#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#pragma comment( lib, "opencv_highgui249d.lib")
#pragma comment(lib,"opencv_imgproc249d.lib")  
#pragma comment(lib, "opencv_core249.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d")   
  
using namespace cv;  
   
//-----------------------------------【main( )函数】--------------------------------------------  
//     描述：控制台应用程序的入口函数，我们的程序从这里开始  
//-----------------------------------------------------------------------------------------------  
int main( )  
{  
       //载入原图  
       Mat image=imread("2.png");  
   
       //创建窗口  
       namedWindow("高斯滤波【原图】" );  
       namedWindow("高斯滤波【效果图】");  
   
       //显示原图  
       imshow("高斯滤波【原图】", image );  
   
       //进行滤波操作  
       Mat out;  
       GaussianBlur(image, out,Size(5, 5),0,0);  
   
       //显示效果图  
       imshow("高斯滤波【效果图】" ,out );  
   
       waitKey(0 );      
}  
