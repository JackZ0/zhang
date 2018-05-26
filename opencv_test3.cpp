#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/calib3d/calib3d.hpp>

#pragma comment( lib, "opencv_highgui249d.lib")
#pragma comment(lib,"opencv_imgproc249d.lib")  
#pragma comment(lib, "opencv_core249.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d")
using namespace std;
using namespace cv;
int main()
{
    Mat image, image_gray;      //定义两个Mat变量，用于存储每一帧的图像
    VideoCapture capture(0);    //从摄像头读入视频
    while (1)                  //循环显示每一帧
    { 
         capture >> image;     //读取当前帧
         cvtColor(image, image_gray, CV_BGR2GRAY);//转为灰度图
         equalizeHist(image_gray, image_gray);//直方图均衡化，增加对比度方便处理    
         CascadeClassifier face_cascade;    //载入分类器
        //加载分类训练器，OpenCv官方文档提供的xml文档，可以直接调用
        //xml文档路径  opencv\sources\data\haarcascades 
        if (!face_cascade.load("C://opencv//sources//data//haarcascades//haarcascade_frontalface_alt.xml"))
        {
            cout << "Load haarcascade_frontalface_alt failed!" << endl;
            return 0;
        }
        //vector 是个类模板 需要提供明确的模板实参 vector<Rect>则是个确定的类 模板的实例化
        vector<Rect> faceRect;
        //检测关于脸部位置
        face_cascade.detectMultiScale(image_gray, faceRect, 1.3, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));//检测
        for (size_t i = 0; i < faceRect.size(); i++)
        {   
            rectangle(image, faceRect[i], Scalar(0, 0, 255));      //用矩形画出检测到的位置
        }
        imshow("人脸识别图", image);         //显示当前帧
        waitKey(30);  
    }
    return 0;
    
}

