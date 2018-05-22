#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/nonfree/features2d.hpp>  
  
#include <iostream>  
  
#pragma comment( lib, "opencv_highgui249d.lib")
#pragma comment(lib,"opencv_imgproc249d.lib")  
#pragma comment(lib, "opencv_core249.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d")  
#pragma comment(lib,"opencv_nonfree249d.lib")
#pragma comment(lib,"opencv_legacy249d.lib")
#pragma comment(lib,"opencv_features2d249d.lib")
using namespace std;  
using namespace cv;  
  
void readme();  
  
int main(int argc,char* argv[])  
{  
    Mat img1 = imread("1.png",CV_LOAD_IMAGE_GRAYSCALE);  
    Mat img2 = imread("4.png",CV_LOAD_IMAGE_GRAYSCALE);  
  
    if(!img1.data || !img2.data)  
    {  
        cout<<"Error reading images!!"<<endl;  
        return -1;  
    }  
  
    SurfFeatureDetector detector;  
    vector<KeyPoint> keypoints1,keypoints2;  
    detector.detect(img1,keypoints1,Mat());  
    detector.detect(img2,keypoints2,Mat());  
      
    SurfDescriptorExtractor extractor;  
    Mat descriptor1,descriptor2;  
    extractor.compute(img1,keypoints1,descriptor1);  
    extractor.compute(img2,keypoints2,descriptor2);  
  
    //FlannBasedMatcher matcher;  
    BFMatcher matcher(NORM_L2);  
    vector<DMatch> matches;  
    matcher.match(descriptor1,descriptor2,matches,Mat());  
  
    Mat imgmatches;  
    drawMatches(img1,keypoints1,img2,keypoints2,matches,imgmatches,Scalar::all(-1),Scalar::all(-1));  
  
    imshow("Matches",imgmatches);  
    waitKey(0);  
    return 0;  
}  
  
void readme()  
{
	cout<<" Usage: ./SURF_descriptor <img1> <img2>"<<endl;
}  
