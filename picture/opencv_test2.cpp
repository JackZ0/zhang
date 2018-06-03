#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <string.h>
#include <opencv/cv.h>
#include <stdio.h>
 
int main(int argc,char *argv[]){
    cv::Mat src1 = cv::imread(argv[1]);
    cv::Mat src2 = cv::imread(argv[2]);
    cv::Mat dst;
 
    double alpha = 0.5; double beta; double input;
 
    beta = (1.0 - alpha);
    addWeighted(src1, alpha, src2, beta, 0.0, dst);
 
    cv::namedWindow("dst");
    cv::imshow("dst",dst);
    cv::waitKey(0);
    return 0;
}
