#include"function.h"

extern char filenameStu[],filenameC[],filenameS[],filenamePsd[];
extern Cinfo c[CNUM];
extern Sinfo s[SNUM];
extern STU stu[NUM],re[NUM];			//学生信息，返回的学生信息
extern int para[NUM];
extern int num,cnum,snum;				//学生总数,学院总数，性别总数 

void sortStudents(STU *s, int *para, int num,CompareMethod cm);
//对num个学生按照指定比较方式排序
void menu8(); 

//hyh
void menu2();
void menu6();
int sortByName(STU x, STU y);
//根据姓名排序
int findName(STU x[], int num, char name[], STU re[]); 
//根据给定的name，从num个x中找出同名，并依次存放到re中，函数返回找到的人数


void menu2()
{
	if (error()) return;
	sortStudents(stu,para,num,sortByName);
	int i;
	for (i=0;i<num;i ++) printStu(stu[para[i]]);
	menu8();
}
/*
stu[i]  7 3 2 1 4 5 6 8 
para[i] 1 2 3 4 5 6 7 8
para[i] 4 3 2 5 6 7 1 8
i       0 1 2 3 4 5 6 7 
*/

void sortStudents(STU *s, int *para, int num, CompareMethod cmp)
{
	int i,j,tmp;
	for(i=0;i<num;i++) para[i]=i;
	//平行数组初始化 
	for(i=0;i<num;i++)
	    for(j=i+1;j<num;j++)
	    	if(cmp(s[para[i]],s[para[j]])){  
				tmp = para[i];
				para[i] = para[j];
				para[j] = tmp;	
			}
}

void menu6()
{
	if (error()) return;
	char s[16];
	printf("请输入学生姓名（完全匹配）：");
	scanf("%s",s);
	int tot = findName(stu,num,s,re);
	if (tot==0) 
	{
		printf("错误：未找到该学生！\n");
	} else 
	{
		int i;
		for (i=0;i<tot;i ++) printStu(re[i]);
	}
}

int sortByName(STU x, STU y) 
{
	return strcmp(x.name,y.name)>0;
}

int findName(STU x[], int num, char name[], STU re[])
{
	int tot = 0,i = 0;
	for (i=0;i<num;i ++)
	{
		if (strcmp(x[i].name,name)==0)
		{
			re[tot] = x[i];
			tot ++;
		}
	}
	return tot;
}//	戴财利
