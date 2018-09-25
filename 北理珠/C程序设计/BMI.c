#include <stdio.h>

int main()
{
	double weight, height; 
	printf("请输入你的体重(kg)和身高(m)，让我们来帮你计算BMI\n");
	scanf("%lf %lf",&weight,&height);
	double BMI = weight / (height*height);
	printf("这是你的BMI指数，BMI：%.2f\n",BMI); 
	return 0;
} 
