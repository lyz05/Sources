#include"function.h"

extern char filenameStu[],filenameC[],filenameS[],filenamePsd[];
extern Cinfo c[CNUM];
extern Sinfo s[SNUM];
extern STU stu[NUM],re[NUM];			//学生信息，返回的学生信息
extern int para[NUM];
extern int num,cnum,snum;				//学生总数,学院总数，性别总数 

void menu8(); 
//yrf
void menu1();
void menu3();
int inputStu(STU stu[], int *num, char filename[]);    
//从文件名filename读num个学生信息到数组stu，并同时计算平均成绩,成功返回真，失败返回假 
int inputCinfo(Cinfo x[], int *num, char filename[]);   
//从文件名filename读num个学院信息到数组x,成功返回真，失败返回假
int inputSinfo(Sinfo x[], int *num, char filename[]);
//从文件名filename读num个性别信息到数组x,成功返回真，失败返回假
void sortStudents(STU *s, int *para, int num,CompareMethod cm);
//对num个学生按照指定比较方式排序
int sortByAve(STU x, STU y);
//根据平均成绩排序

void menu1()
{
	if (inputStu(stu,&num,filenameStu))
		printf("读入学生信息成功，共读入%d个信息\n",num);
	else
		printf("错误：读入学生信息失败\n");
	if (inputCinfo(c,&cnum,filenameC))
		printf("读入学院信息成功，共读入%d个信息\n",cnum);
	else
		printf("错误：读入学院信息失败\n"); 
	if (inputSinfo(s,&snum,filenameS)) 
		printf("读入性别信息成功，共读入%d个信息\n",snum);
	else
		printf("错误：读入性别信息失败\n");
}

void menu3()
{
	if (error()) return;
	sortStudents(stu,para,num,sortByAve);
	int i;
	for (i=0;i<num;i ++) printStu(stu[para[i]]);
	menu8();
}

int inputStu(STU stu[], int *num, char filename[])
{
	FILE *fp;
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("Can't not open this file");
		return 0;
	} 
	if(ferror(fp))
	{
		printf("This file has error");
		return 0;
	}
	char s[100];
	while (1)
	{
		int n; 
		fgets(s,sizeof (s),fp);
		if(s[0]=='#')
			continue;
		sscanf(s,"%d",&n);
		*num = n;
		//printf("%d\n",n);
		int i,j;
		for(i=0;i<n;i++)
		{
			fscanf(fp,"%d %s %d %d",&stu[i].id,stu[i].name,&stu[i].sid,&stu[i].cid);
			stu[i].ave=0;
			for(j=0;j<10;j++) 
			{ 
				fscanf(fp,"%d",&stu[i].score[j]);
				stu[i].ave+=stu[i].score[j];
			}
			stu[i].ave=stu[i].ave/10;
		}

	//	for(i=0;i<n;i++)
	//		{
	//			printf("学号是：%d\n 姓名是：%s\n 性别是：%d\n 学院是：%d\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].college);
	//			printf("第%d的成绩是：%d\n",j+1,stu[i].score[j]);
	//		}
			break;		
	}
	fclose(fp);	
	return 1;
} 

int inputCinfo(Cinfo x[], int *num, char filename[])
{
	FILE *fp;
	fp=fopen(filename,"r");
	char b[100];
	while(1)
	{
		fgets(b,sizeof (b),fp);
		if(b[0]=='#')
			continue;
		int i,h;
		sscanf(b,"%d",&h);
		*num = h;
		for(i=0;i<h;i++)
		{
			fscanf(fp,"%d %s",&x[i].id,x[i].name);
	//		printf("%d\n %s\n",x[i].id,x[i].name);
		}
		break;
	}
	return 1;
} 

int inputSinfo(Sinfo x[], int *num, char filename[])
{
	FILE *fp;
	fp=fopen(filename,"r");
	char p[100];
	while(1)
	{
		fgets(p,sizeof(p),fp);
		if(p[0]=='#')
			continue;
		int i,q;
		sscanf(p,"%d",&q);	
		*num = q;
		for(i=0;i<q;i++)
		{
			fscanf(fp,"%d %s",&x[i].id,x[i].name);
		//	printf("%d %s\n",x[i].id,x[i].name);
		}
		break;
	}	
	return 1;
} 

int sortByAve(STU x, STU y) {return x.ave < y.ave;}

