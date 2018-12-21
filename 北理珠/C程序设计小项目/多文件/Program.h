#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>			//密码输入 
#include<io.h>				//文件存在检测 

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


void menu2();
void menu4();
void menu5();
void menu6();
void menu7();
void menu8();
void menu0();
int error();								//未读入文件检测 
void init();								//系统初始化&密码检测 
void printStu(STU stu);
void seekPos(FILE *fp);
//过滤文件中最顶部的注释 


int sortByName(STU x, STU y);
//根据姓名排序
int findName(STU x[], int num, char name[], STU re[]); 
//根据给定的name，从num个x中找出同名，并依次存放到re中，函数返回找到的人数
int ModifyStuinfo(STU x[], int num, int id, char filename[]);
//根据给定的学生学号修改该学生的信息
int JudgePsd(char psd[]);
//判断密码正确性
int ModifyPsd(char psd[],char filename[]);
//修改密码，返回修改是否成功
char* encodeInp(char *input);
//对密码进行加密 
void InputPsd(char psd[]);
//密码输入函数 


//yrf
void menu1();
int inputStu(STU stu[], int *num, char filename[]);    
//从文件名filename读num个学生信息到数组stu，并同时计算平均成绩,成功返回真，失败返回假 
int inputCinfo(Cinfo x[], int *num, char filename[]);   
//从文件名filename读num个学院信息到数组x,成功返回真，失败返回假
int inputSinfo(Sinfo x[], int *num, char filename[]);
//从文件名filename读num个性别信息到数组x,成功返回真，失败返回假
void menu3();
int sortByAve(STU x, STU y);
//根据平均成绩排序
void sortStudents(STU *s, int *para, int num,CompareMethod cm);
//对num个学生按照指定比较方式排序

