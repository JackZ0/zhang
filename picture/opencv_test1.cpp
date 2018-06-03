#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <string.h>
#include <opencv/cv.h>
#include <stdio.h>
 
int main(int argc,char *argv[]){
    cv::Mat src1 = cv::imread(argv[1]);
    cv::Mat src2 = cv::imread(argv[2]);
 
    cv::Mat imageROI= src1(cv::Rect(200,250,src2.cols,src2.rows));
    src2.copyTo(imageROI);
 
    cv::namedWindow("dst");
    cv::imshow("dst",src1);
    cv::waitKey(0);
    return 0;
}
