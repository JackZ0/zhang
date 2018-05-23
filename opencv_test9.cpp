#include <windows.h>  
#include <mmsystem.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include "wininet.h"  
#include <direct.h>  
#include <string.h>  
#include <list>  

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
#include <stdio.h>
#include <iostream>
#include <vector>  
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
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

#define MAX_CORNERS 100  
   
int main()  
{  
    Mat img_1 = imread("1.png");  
    Mat img_2 = imread("2.png"); 

    if (!img_1.data || !img_2.data)  
    {  
        cout << "error reading images " << endl;  
        return -1;  
    }  

    // 声明特征子
    ORB orb;  
    vector<KeyPoint> keyPoints_1, keyPoints_2;  
    Mat descriptors_1, descriptors_2;  

    // 开始检测
    orb(img_1, Mat(), keyPoints_1, descriptors_1);  
    orb(img_2, Mat(), keyPoints_2, descriptors_2);  

    // 检测完成后进行匹配
    BruteForceMatcher<HammingLUT> matcher;

    vector<DMatch> matches;  

    matcher.match(descriptors_1, descriptors_2, matches);  

    // 显示匹配的结果
    Mat img_matches;  

    drawMatches(img_1, 
                keyPoints_1, 
                img_2, 
                keyPoints_2, 
                matches, 
                img_matches, 
                Scalar::all(-1), 
                Scalar::all(-1),  
                vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    cv::namedWindow("ORB Features");  // 可以不写
    imshow("ORB Features", img_matches);  

    cvWaitKey(0);  
    return 0;  
}
