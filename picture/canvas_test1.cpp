#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;
int main()
{
	Mat M=imread("./1.jpg");
	Vec3i color;
	for(int col =600; col<640; col++)
	{
		for(int row=310;row<350;row++)
		{
			color[0] = (int)(*(M.data + M.step[0] * row + M.step[1] *col));
			color[1] = (int)(*(M.data + M.step[0] * row + M.step[1] * col + M.elemSize1()));
			color[2] = (int)(*(M.data + M.step[0] * row + M.step[1] * col + M.elemSize1()*2));

			cout << color[0]<< ","<< color[1] << "," << color[2] << " ===>";

			color[0] = 255;
			color[1] = 255;
			color[2] = 0;
			*(M.data + M.step[0]*row + M.step[1]*col) = color[0];
			*(M.data + M.step[0]*row + M.step[1]*col + M.elemSize1()) = color[1];
			*(M.data + M.step[0] * row + M.step[1] * col + M.elemSize1()*2) = color[2];

			cout << (int)*(M.data + M.step[0]*row + M.step[1]*col) << *(M.data + M.step[0]*row + M.step[1]*col +1) << *(M.data + M.step[0]*row + M.step[1]*col+2) << endl;

		}
	}
	imshow("canvas",M);
	cvWaitKey(0);
	return 0;
}
