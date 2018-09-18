#include<stdio.h>

const double pi = 3.141592654; 

int main()
{
	double r;
	printf("请输入圆的半径\n");
	scanf("%lf",&r);
	double s = pi * r * r,c = 2 * pi * r;
	printf("圆的周长C是：%f，圆的面积S是：%f\n",c,s);
	return 0;
}
