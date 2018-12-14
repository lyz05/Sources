#include<stdio.h>
#include<string.h>
#ifndef _COMMON
#define _COMMON
typedef struct c{
	int id;
	char name[32];
}Cinfo;
Cinfo c[10];
typedef struct gd{
	int id;
	char name[16];
}Sinfo;
Sinfo s[3];
typedef struct stu{
	int id;
	char name[16];
	int sid;//性别代码
	int cid;//学院代码
	int score[10];//10门成绩
	float ave;//平均
	int nm;//成绩名次 
}STU;
STU stu[100];

int inputStu(STU stu[], int num, char filename[]);
#endif
