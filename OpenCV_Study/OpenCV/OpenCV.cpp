#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/saturate.hpp>
#include <iostream>
#include <algorithm>

using namespace cv;
using namespace std;

RNG rng(12345);						//随机数函数
int main(int argc, char** argv)
{
	String filename = "003.jpg",outputfilename = "003_out.jpg";

	//读入图片
	Mat src,dst,dst1;
	src = imread(filename, IMREAD_COLOR); // Read the file

	if (src.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	//imshow("src window", src); // Show our image inside it.
	//转换为灰度图像
	cvtColor(src, dst, COLOR_BGR2GRAY);
	//imshow("src_gray window", dst);

	//提高图像对比度
	int rows = dst.rows, cols = dst.cols;
	int alpha = 2.2;		//(alphe > 1)
	int beta = 0;			// 负数对比度越高
	for (int i = 0;i < rows;i ++)
		for (int j = 0; j < cols; j++)
		{
			dst.at<uchar>(i, j) = saturate_cast<uchar>(alpha * dst.at<uchar>(i, j) + beta);
		}
	//imshow("dst window", dst);
	
	//图像二值化
	threshold(dst, dst1, 100, 255, THRESH_BINARY);
	//imshow("dst1 window", dst1);
	
	//膨胀
	int structElementSize = 2;
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * structElementSize + 1, 2 * structElementSize + 1), Point(structElementSize, structElementSize));
	dilate(dst1, dst1, element);
	//imshow("dst2 window", dst2);
	
	//闭运算，消除扇叶上可能存在的小洞
	structElementSize = 3;
	element = getStructuringElement(MORPH_RECT, Size(2 * structElementSize + 1, 2 * structElementSize + 1), Point(structElementSize, structElementSize));
	morphologyEx(dst1, dst1, MORPH_CLOSE, element);
	//imshow("dst3 window", dst2);
	
	//查找轮廓
	vector<vector<Point>> contours2;			//查找到的轮廓
	vector<Vec4i> hierarchy2;
	findContours(dst1, contours2, hierarchy2, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

	RotatedRect rect_tmp2;
	bool findTarget = 0;

	//画出所有轮廓
	Mat drawing = Mat::zeros(src.size(), CV_8UC3);
	
	for (size_t i = 0; i < contours2.size(); i++)
	{
		float Contour_Area = contourArea(contours2[i]);
		cout << i << " " << Contour_Area <<" " << contours2[i].size() << endl;
		Scalar color = Scalar(rng.uniform(0,256), rng.uniform(0, 256), rng.uniform(0, 256));
		drawContours(drawing, contours2, (int)i, color, 2, LINE_8, hierarchy2, 0);
		//imshow("Contours", drawing);
		//waitKey(0);
	}
	//计算几何中心点
	Point point_draw(0,0);
	int id = contours2.size() - 1;
	for (int i = 0; i < contours2[id].size(); i ++)
	{
		point_draw.x += contours2[id][i].x;
		point_draw.y += contours2[id][i].y;
	}
	point_draw.x /= contours2[id].size();
	point_draw.y /= contours2[id].size();
	//cout << contours2[id] << endl;
	cout << "目标中心坐标：" << point_draw.x << " " << point_draw.y << endl;
	circle(drawing, point_draw, 2, Scalar(0, 256, 0));

	imshow("Contours", drawing);
	imwrite(outputfilename, drawing);
	
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}
