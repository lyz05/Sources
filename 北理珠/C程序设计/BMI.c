#include <stdio.h>

int main()
{
	double weight, height; 
	printf("�������������(kg)�����(m)�����������������BMI\n");
	scanf("%lf %lf",&weight,&height);
	double BMI = weight / (height*height);
	printf("�������BMIָ����BMI��%.2f\n",BMI); 
	return 0;
} 
