#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;
int main()
{
	Mat m(400,400,CV_8U,Scalar(0));
	for(int col=0;col<400;col++)
	{
		for(int row=23;row<170;row++)
		{
			cout<<(int)(*(m.data+m.step[0]*row+m.step[1]*col))<<"  ===> ";
			*(m.data+m.step[0]*row + m.step[1]*col)=154;
			cout<<(int)(*(m.data+m.step[0]*row+m.step[1]*col))<<endl;
		}
	}
	imshow("canvas",m);
	cvWaitKey(0);
	return 0;
}
