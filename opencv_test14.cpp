#include <string.h>  
#include <afx.h>
#include <fstream>
#include <iostream>
#include <vector>  
#include <math.h>
#include <time.h>
#include <io.h>
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
#include <opencv2/ml/ml.hpp>

#pragma comment( lib, "opencv_highgui249d.lib")
#pragma comment(lib,"opencv_imgproc249d.lib")  
#pragma comment(lib, "opencv_core249.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d.lib")   
#pragma comment(lib,"opencv_photo249d.lib")   
#pragma comment(lib,"opencv_nonfree249d.lib")   
#pragma comment(lib,"opencv_features2d249d.lib")   
#pragma comment(lib,"opencv_ml249d.lib")
  
using namespace cv;  
using namespace std;
int main()
{
	Mat src = imread("1.jpg");
    imshow("img", src);

    Mat means, stddev, covar;
    meanStdDev(src, means, stddev);//计算src图片的均值和标准差
    printf("means rows:%d,means cols %d\n", means.rows, means.cols);//RGB三通道，所以均值结果是3行一列
    printf("stddev rows:%d,means cols %d\n", stddev.rows, stddev.cols);

    for (int row = 0; row < means.rows; row++)
    {
        printf("mean %d = %.3f\n", row, means.at<double>(row));
        printf("stddev %d = %.3f\n", row, stddev.at<double>(row));
    }
	waitKey();
}
