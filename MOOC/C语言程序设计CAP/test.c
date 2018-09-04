#include <stdio.h>
#define e 9//这是全局常量

const int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};//这是全局常量，生效范围为整个程序。
int b;//这是全局变量

void main() 
{
	const int c;//这是局部常量，生效范围为该语句到函数结束前。
	int d;//这是局部变量
}