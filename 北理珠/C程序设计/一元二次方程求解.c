#include<stdio.h>
#include<math.h>

int main()
{
	int a,b,c;
	printf("请输入需要求解的一元二次方程的系数a,b,c:\n");
	printf("a=");scanf("%d",&a);
	printf("b=");scanf("%d",&b);
	printf("c=");scanf("%d",&c);
	//输入系数 
	double delta = b*b-4*a*c,x1,x2;
	x1 = (-b*1.0-sqrt(delta))/(2*a*1.0);
	x2 = (-b*1.0+sqrt(delta))/(2*a*1.0);
	//方程求解 
	//printf("你要解的方程是：%dx^2+%dx+%d=0\n",a,b,c);
	if (a==0 && b==0)
		if (c==0) {
			printf("该式为恒等式\n");
			return 0;	
		}
		else {
			printf("该式不成立\n");
			return 0;	
		}
	if (delta<0) printf("方程不存在实数根\n");else
		if (delta==0) printf("方程只有一个实数根:x=%f\n",x1);else
			if (a==0) printf("这不是一个一元二次方程\n"); else 
				printf("方程的两个根是：x1=%f,x2=%f\n",x1,x2);
	//根的判断 
	
	return 0;
}
//scanf("%d%d%d",&a,&b,&c);
//x=(-b+-sart(delta))/(2a)
	
