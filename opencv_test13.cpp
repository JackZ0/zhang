 
#include <string.h>  
#include <afx.h>
#include <fstream>
#include <iostream>
#include <vector>  
#include <time.h>
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
#pragma comment(lib, "opencv_core249.lib")
#pragma comment(lib,"opencv_contrib249d.lib")
#pragma comment(lib,"opencv_objdetect249d.lib")   
#pragma comment(lib,"opencv_photo249d.lib")   
#pragma comment(lib,"opencv_nonfree249d.lib")   
#pragma comment(lib,"opencv_features2d249d.lib")   

  
using namespace cv;  
using namespace std;

int main()
{
 int n=0;
	   WIN32_FIND_DATAA FileData;  
    HANDLE hFind;  
        
    hFind = FindFirstFileA((LPCSTR)"C://posdata//*.jpg",&FileData); 
    if (hFind == INVALID_HANDLE_VALUE)
    {  
        printf ("Invalid File Handle. GetLastError reports %d\n", GetLastError ());  
        return 0;  
    } 
    while (FindNextFileA(hFind, &FileData))
    {  
        cout<<FileData.cFileName<<endl;  
        string name("C://posdata//");  
        name.append(FileData.cFileName); 
		IplImage* src=cvLoadImage(name.c_str(),-1);  
        if (!src)
        {  
            cout<<"failed to load image"<<endl;  //API
           // AfxMessageBox("failed to load image"); //MFC
            break;  
        }  
        //assert(src->nChannels==1);
		
		IplImage *pDstImage = NULL;
		 CvSize czSize;              //目标图像尺寸  
		 czSize.width =32;
         czSize.height = 32;
		 pDstImage = cvCreateImage(czSize,  src->depth,src->nChannels);
		 cvResize(src, pDstImage, CV_INTER_AREA); 
		 cvSaveImage(name.c_str(),pDstImage);
     //   cvReleaseImage(&src);  
//        cvReleaseImage(&pDstImage);  
//		cout<<name<<endl;
		n++;
		cout<<n<<endl;   
    }    
    FindClose(&hFind); 
}
