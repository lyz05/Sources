#include<stdio.h>

const double pi = 3.141592654; 

int main()
{
	double r;
	printf("������Բ�İ뾶\n");
	scanf("%lf",&r);
	double s = pi * r * r,c = 2 * pi * r;
	printf("Բ���ܳ�C�ǣ�%f��Բ�����S�ǣ�%f\n",c,s);
	return 0;
}
