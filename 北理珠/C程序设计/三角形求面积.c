#include <stdio.h>
#include <math.h> 

int main()
{
	float a,b,c;
	printf("请依次输入三角形的三边长\n");
	scanf("%f%f%f",&a,&b,&c);
	float p = (a+b+c)/2,s = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("三角形的面积S=%f",s);
	return 0;
}
