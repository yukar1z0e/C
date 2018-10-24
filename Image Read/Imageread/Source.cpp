#include<opencv.hpp>
#include<stdio.h>
using namespace cv;

int main() {
	Mat img = imread("1.jpg");
	if (img.empty()){
		printf("error");
		system("pause");
		return -1;
	}
	namedWindow("Exa1", WINDOW_AUTOSIZE);
	imshow("Exa1", img);
	printf("succeed");
	waitKey(0);
	//system("pause");
	destroyWindow("Exa1");
	return 0;
}
