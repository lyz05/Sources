#include <stdio.h>
#include <math.h> 

int main()
{
	float a,b,c;
	printf("���������������ε����߳�\n");
	scanf("%f%f%f",&a,&b,&c);
	float p = (a+b+c)/2,s = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("�����ε����S=%f",s);
	return 0;
}
