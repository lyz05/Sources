#include<stdio.h>

const double pi = 3.141592654;

int main()
{
	double r;
	printf("请输入球的半径\n");
	scanf("%lf",&r);
	double s = 4.0*pi*r*r,v = (4.0*pi*r*r*r)/3;
	printf("球的表面积是：%f,球的体积是：%f\n",s,v);
	return 0;
}
