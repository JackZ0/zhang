#include <string.h>  
#include <afx.h>
#include <fstream>
#include <iostream>
#include <vector>  
//#include <time.h>
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
#pragma comment(lib, "opencv_core249d.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d.lib")   
#pragma comment(lib,"opencv_photo249d.lib")   
#pragma comment(lib,"opencv_nonfree249d.lib")   
#pragma comment(lib,"opencv_features2d249d.lib")   
#pragma comment(linker,"/subsystem:windows /ENTRY:mainCRTStartup")

using namespace cv;  
using namespace std;
using std::vector;
int main()
{
	int n=0;
	WIN32_FIND_DATAA FileData;  
    HANDLE hFind;  
        
    hFind = FindFirstFileA((LPCSTR)"C://opencv_test//pos//*.jpg",&FileData); 
    if (hFind == INVALID_HANDLE_VALUE)
    {  
        printf ("Invalid File Handle. GetLastError reports %d\n", GetLastError ());  
        return 0;  
    } 
    while (FindNextFileA(hFind, &FileData))
    {  
        cout<<FileData.cFileName<<endl;  
        string name("C://opencv_test//pos//");  
        name.append(FileData.cFileName); 
		Mat src=imread(name.c_str()),grayImage; 
        cvtColor(src,grayImage,CV_BGR2GRAY);
		 
		imwrite(name.c_str(),grayImage);
		n++;
		cout<<n<<endl;   
    }    
    FindClose(&hFind); 
}
