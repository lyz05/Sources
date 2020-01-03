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
	if ((fp = fopen(filename,"r"))==NULL) return 0;
	seekPos(fp);
		
	int i,j;
	//跳到读写位置 
	fscanf(fp,"%d",num);
	for (i=0;i<(*num);i ++)
	{
		fscanf(fp,"%d %s %d %d",&stu[i].id,stu[i].name,&stu[i].sid,&stu[i].cid);
		if (ferror(fp)) return 0;
		//printf("%d %s %d %d",stu[i].id,stu[i].name,stu[i].sid,stu[i].cid); 
		stu[i].ave = 0;
		for (j=0;j<10;j ++)
		{
			fscanf(fp,"%d",&stu[i].score[j]);
			if (ferror(fp)) return 0;
			stu[i].ave += stu[i].score[j];
			//printf("%d ",stu[i].score[j]);
		}
		stu[i].ave /= 10;
		//printf("%f\n",stu[i].ave);
	}
	
	
	if (fclose(fp)==EOF) return 0;
	return 1;
}

int inputCinfo(Cinfo x[], int *num, char filename[])
{
	FILE *fp;
	if ((fp = fopen(filename,"r"))==NULL) return 0;
	seekPos(fp);
	
	int i; 
	fscanf(fp,"%d",num);
	for (i=0;i<(*num);i ++)
	{
		fscanf(fp,"%d %s",&x[i].id,x[i].name);
		//printf("%d %s\n",x[i].id,x[i].name);
		if (ferror(fp)) return 0;
	}
	
	if (fclose(fp)==EOF) return 0;
	return 1;
} 

int inputSinfo(Sinfo x[], int *num, char filename[])
{
	FILE *fp;
	if ((fp = fopen(filename,"r"))==NULL) return 0;
	seekPos(fp);
	
	int i; 
	fscanf(fp,"%d",num);
	for (i=0;i<(*num);i ++)
	{
		fscanf(fp,"%d %s",&x[i].id,x[i].name);
		//printf("%d %s\n",x[i].id,x[i].name);
		if (ferror(fp)) return 0;
	}
	
	if (fclose(fp)==EOF) return 0;
	return 1;	
} 

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

int sortByAve(STU x, STU y) {return x.ave < y.ave;}

