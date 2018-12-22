#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>			//密码输入
#include<io.h>				//文件存在检测
#define NUM 100				//学生最大值
#define CNUM 10				//学院最大值
#define SNUM 3				//性别信息最大值

typedef struct c{
	int id;
	char name[32];
}Cinfo;
//学院信息
typedef struct gd{
	int id;
	char name[16];
}Sinfo;
//性别信息
typedef struct stu{
	int id;
	char name[16];
	int sid;				//性别代码
	int cid;				//学院代码
	int score[10];			//10门成绩
	float ave;				//平均成绩 
	//int nm;				//成绩名次
}STU;
//学生信息 

typedef int (*CompareMethod)(STU x,STU y);
//CompareMethod 比较方式函数指针


int error();								//未读入文件检测 
void init();								//系统初始化&密码检测 
void printStu(STU stu);
void seekPos(FILE *fp);
//过滤文件中最顶部的注释 
void InputPsd(char psd[]);
//密码输入函数
int InputNum(int *num);
//从stdin中读入一个数字，返回成功与否 


