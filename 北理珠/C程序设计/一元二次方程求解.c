#include<stdio.h>
#include<math.h>

int main()
{
	int a,b,c;
	printf("请输入需要求解的一元二次方程的系数a,b,c:\n");
	scanf("%d%d%d",&a,&b,&c);
	double delta = b*b-4*a*c,x1,x2;
	x1 = (-b*1.0-sqrt(delta))/(2*a*1.0);
	x2 = (-b*1.0+sqrt(delta))/(2*a*1.0);
	printf("方程的两个根是：x1=%f,x2=%f\n",x1,x2);
	//x=(-b+-sart(delta))/(2a)
	
	return 0;
}
