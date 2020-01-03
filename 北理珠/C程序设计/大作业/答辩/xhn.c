#include"function.h"

extern char filenameStu[],filenameC[],filenameS[],filenamePsd[];
extern Cinfo c[CNUM];
extern Sinfo s[SNUM];
extern STU stu[NUM];			//学生信息，返回的学生信息
extern int num,cnum,snum;				//学生总数,学院总数，性别总数 

//xhn
void menu4();
void menu8();								//菜单显示
void menu0();


void menu4()
{
	if (error()) return;
	puts("********************请指定一个学院*****************************");
	int i;
	for (i=0;i<cnum;i ++) 
		printf("%d. %s\n",c[i].id,c[i].name);
	puts("***************************************************************");
	while (1)
	{
		int n;
		printf("请输入学院代码:");
		if (InputNum(&n) == 0) continue; 
		for (i=0;i<num;i ++) 
			if (stu[i].cid==n)
				printStu(stu[i]); 
		break;
	}
	menu8();
}

void menu0()
{
	exit(0);
}

void menu8()
{
	puts("********************学生成绩管理系统***************************");
	puts("1. 原始文件读取");
	puts("2. 按姓名排序并输出");
	puts("3. 按平均成绩排序并输出");
	puts("4. 输出给定学院学生");
	puts("5. 修改给定学生成绩信息（修改后的信息，需输出到文件）");
	puts("6. 按姓名查询学生并输出");
	puts("7. 修改系统密码");
	puts("8. 显示菜单");
	puts("0. 结束系统");
	puts("***************************************************************"); 
} 

