#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/saturate.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int bmain()
{
	String filename = "002.jpg",outputfilenme = "002_out.jpg";
	Mat src,dst;
	src = imread(filename, IMREAD_COLOR); 

	if (src.empty()) 
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	cvtColor(src, dst, COLOR_BGR2GRAY);
	dst = src.clone();
	//Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC3);
	//imshow("src window", src); // Show our image inside it.
	int rows = src.rows, cols = src.cols;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			int b = src.at<Vec3b>(i, j)[0];
			int g = src.at<Vec3b>(i, j)[1];
			int r = src.at<Vec3b>(i, j)[2];
			dst.at<Vec3b>(i, j)[1] = 0;
			dst.at<Vec3b>(i, j)[2] = 0;
			dst.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(b-r);
		}
	//imshow("dst window", dst); // Show our image inside it.
	imwrite(outputfilenme, dst);
	//waitKey(0); // Wait for a keystroke in the window
	return 0;
}