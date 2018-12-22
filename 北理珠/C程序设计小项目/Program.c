#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>			//密码输入
#include<io.h>			//文件存在检测
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

void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void menu6();
void menu7();
void menu8();								//菜单显示
void menu0();
//目录信息
int error();								//未读入文件检测 
void init();								//系统初始化&密码检测 
void printStu(STU stu);
void seekPos(FILE *fp);
//过滤文件中最顶部的注释 
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
int sortByName(STU x, STU y);
//根据姓名排序
int findName(STU x[], int num, char name[], STU re[]); 
//根据给定的name，从num个x中找出同名，并依次存放到re中，函数返回找到的人数
int ModifyStuinfo(STU x[], int num, int id, char filename[]);
//根据给定的学生学号修改该学生的信息
int JudgePsd(char psd[],char filename[]);
//判断密码正确性
int ModifyPsd(char psd[],char filename[]);
//修改密码，返回修改是否成功
char* encodeInp(char *input);
//对密码进行加密 
void InputPsd(char psd[]);
//密码输入函数
int InputNum(int *num);
//从stdin中读入一个数字，返回成功与否 

char filenameStu[]="data1\\Stu_Info3.txt",filenameC[]="data1\\C_Info1.txt",filenameS[]="data1\\S_Info2.txt",filenamePsd[]="data1\\psd.txt";
Cinfo c[CNUM];
Sinfo s[SNUM];
STU stu[NUM],re[NUM];						//学生信息，返回的学生信息
int para[NUM];
int num = 0,cnum = 0,snum = 0;				//学生总数,学院总数，性别总数 

int main()
{
	init();									//密码检测 
	menu8();
	int n;
	while (1)
	{
		printf("请输入要进行的模块:");
		if (!InputNum(&n)) continue;
		switch (n)
		{
			case 1:	menu1(); break;
			case 2:	menu2(); break;
			case 3: menu3(); break;
			case 4:	menu4(); break;
			case 5:	menu5(); break;
			case 6:	menu6(); break;
			case 7:	menu7(); break;
			case 8:	menu8(); break;
			case 0:	menu0(); break;
			default:printf("错误：输入有误！请重新输入\n");
		}
	}
	return 0;
} 

int error()
{
	if (num==0) printf("错误：你还未读入相关信息，请先进行原始文件读取\n");
	return (num==0);
} 

void menu0()
{
	exit(0);
}

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

void menu2()
{
	if (error()) return;
	sortStudents(stu,para,num,sortByName);
	int i;
	for (i=0;i<num;i ++) printStu(stu[para[i]]);
	menu8();
}

void menu3()
{
	if (error()) return;
	sortStudents(stu,para,num,sortByAve);
	int i;
	for (i=0;i<num;i ++) printStu(stu[para[i]]);
	menu8();
}

void menu4()
{
	if (error()) return;
	puts("********************请指定一个学院*****************************");
	int i;
	for (i=0;i<cnum;i ++) printf("%d. %s\n",c[i].id,c[i].name);
	puts("***************************************************************");
	while (1)
	{
		int n;
		printf("请输入学院代码:");
		if (!InputNum(&n)) continue;
		for (i=0;i<cnum && c[i].id!=n;i ++);
		if (i==cnum)									//未在学院结构体中找到相应的数字 
		{
			printf("错误：输入有误！请重新输入\n");
			continue;
		}
		for (i=0;i<num;i ++) 
			if (stu[i].cid==n)
				printStu(stu[i]); 
		break;
	}
	menu8();
}

void menu5()
{
	if (error()) return;
	int id;
	printf("请输入学生学号：");
	scanf("%d",&id);
	if (ModifyStuinfo(stu,num,id,filenameStu))
		printf("修改学生信息成功！\n");
	else
		printf("修改学生信息失败！\n");
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

void menu7()
{
	fflush(stdin);
	char old[100],new[2][100];
	if (!JudgePsd("",filenamePsd)) 
	{
		printf("请输入旧密码：");
		InputPsd(old);
		if (!JudgePsd(old,filenamePsd))
		{
			printf("错误：密码错误！\n");
			return; 
		}
	}
	printf("请输入新密码：");
	InputPsd(new[0]);
	printf("请再次输入新密码：");
	InputPsd(new[1]);
	if (strcmp(new[0],new[1])!=0)
	{
		printf("错误：输入的两次新密码不同\n");
		return;
	}
	if (ModifyPsd(new[0],filenamePsd))
		printf("修改密码成功！\n");
	else
		printf("修改密码失败！\n");
}

void init()
{
	if (!JudgePsd("",filenamePsd)) 
	{
		char s[100];
		while (1)
		{
			printf("请输入密码以启动系统：");
			//gets(s);
			InputPsd(s);
			if (s[0]=='\0') continue;
			if (!JudgePsd(s,filenamePsd))
			{
				printf("错误：密码错误！\n");
				continue; 
			}
			break;
		}
	}
	system("cls");
} 

void InputPsd(char psd[])
{
	int tot;
	char ch;
    for (tot = 0;(ch = (char)getch ()) != '\r';tot ++) {
    	if (ch=='\b')
    	{
			if (tot!=0)
    		{
    			tot -= 2;
    			printf("\b \b");
			} else tot --;
		} else
		{
        	psd[tot] = ch;
			putchar('*');
		}
    }
    psd[tot] = '\0';
    printf("\n");
    //printf("%s\n",psd);
    return;
}

void printStu(STU stu)
{
	int i;
	char sname[100],cname[100];
	for (i=0;i<snum;i ++) 
		if (s[i].id==stu.sid) strcpy(sname,s[i].name);
	for (i=0;i<cnum;i ++) 
		if (c[i].id==stu.cid) strcpy(cname,c[i].name); 
	printf("学号：%d\t姓名：%s\t性别：%s\t学院：%s\n",stu.id,stu.name,sname,cname);
	printf("该学生的%d门课成绩信息：\n",10);
	for (i=0;i<10;i ++)	printf("%d\t",stu.score[i]);
	printf("\n");
	printf("平均分：%f\n\n",stu.ave);
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

int sortByAve(STU x, STU y) {return x.ave < y.ave;}
int sortByName(STU x, STU y) {return strcmp(x.name,y.name)>0;}
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

int findName(STU x[], int num, char name[], STU re[])
{
	int tot = 0,i = 0;
	for (i=0;i<num;i ++)
	{
		if (strcmp(x[i].name,name)==0)
		{
			re[tot ++] = x[i];
		}
	}
	return tot;
}//戴财利 

int ModifyStuinfo(STU x[], int num, int id, char filename[])
{
	int flag = 0;
	FILE *fp;
	if ((fp = fopen(filename,"r+"))==NULL) return 0;
	seekPos(fp);
	char s[500];
	
	//fprintf(fp,"%d",20);
	fgets(s,sizeof s,fp);									//忽略总数 
	fseek(fp,0,SEEK_CUR);									//转为写操作 
	int i,j,n;
	for (i=0;i<num;i ++)
	{
		if (x[i].id == id)
		{
			printf("修改前：\n");
			printStu(x[i]);
			while (1)
			{
				printf("请输入您要修改成绩的编号(1~10)：");	
				if (scanf("%d",&n)!=1 || n>10 || n<1) 
    			{
					while(getchar()!='\n');					//清除缓冲区数据 
					printf("输入有误！请重新输入！\n");
					continue;
				}
				break; 
			}
			printf("请输入新成绩：");
			int score;
			scanf("%d",&score);
			x[i].score[n-1] = score;
			{
				for (j=0,x[i].ave=0;j<10;j ++) x[i].ave += x[i].score[j];
				x[i].ave /= 10;
			}//重算平均分 	
			printf("修改后：\n");
			printStu(x[i]);
			flag = 1;
		}
		//文件操作
		fprintf(fp,"%d %s %d %d ",x[i].id,x[i].name,x[i].sid,x[i].cid);
		//printf("%d\n",ferror(fp));
		if (ferror(fp)) return 0;
		//printf("%d %s %d %d",stu[i].id,stu[i].name,stu[i].sid,stu[i].cid); 
		for (j=0;j<10;j ++)
		{
			fprintf(fp,"%d ",x[i].score[j]);
			if (ferror(fp)) return 0;
			//printf("%d ",stu[i].score[j]);
		}
		fprintf(fp,"\n");
		if (ferror(fp)) return 0;
		//fgets(s,sizeof s,fp);
	}
	if (fclose(fp)==EOF) return 0;
	if (!flag)
		printf("找不到学号为%d的学生\n",id);
	return flag;
}

int JudgePsd(char psd[],char filename[])
{
	char data[100]={}; 
	char *encode = encodeInp(psd);
	if (access(filename,F_OK)==-1) return 1;	//空密码 
	FILE *fp = fopen(filename,"r");
	if (fp==NULL)
	{
		printf("错误：打开文件失败！\n");
		return 0;
	}
	fgets(data,sizeof data,fp);
	if (fclose(fp)==EOF) return 0;
	return (strcmp(data,encode)==0);
}

int ModifyPsd(char psd[],char filename[])
{
	char *encode = encodeInp(psd);
	//if (access(filename,F_OK)==-1) return 1;	//空密码 
	FILE *fp = fopen(filename,"w");
	if (fp==NULL)
	{
		printf("错误：打开文件失败！\n");
		return 0;
	}
	fputs(encode,fp);
	if (ferror(fp)) return 0;
	if (fclose(fp)==EOF) return 0;
	return 1;
}

char* encodeInp(char *input)
{
	const char keyStr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	static char output[100];
	memset(output,0,sizeof output);
	int chr1,chr2,chr3;
	int enc1,enc2,enc3,enc4;
	int i=0,tot = 0;
	while (i < strlen(input)){
		chr1 = input[i++];
		chr2 = input[i++];
		chr3 = input[i++];
		enc1 = chr1 >> 2;
		enc2 = ((chr1 & 3) << 4) | (chr2 >> 4);
		enc3 = ((chr2 & 15) << 2) | (chr3 >> 6);
		enc4 = chr3 & 63;
		if(chr2==0)
		{
			enc3 = enc4 = 64;
		} else if (chr3==0)
		{
			enc4 = 64;
		}
		output[tot ++]=keyStr[enc1];
		output[tot ++]=keyStr[enc2];
		output[tot ++]=keyStr[enc3];
		output[tot ++]=keyStr[enc4];
		
		chr1 = chr2 = chr3 = 0;
		enc1 = enc2 = enc3 = enc4 = 0;
		
	};
	return output;
}

void seekPos(FILE *fp)
{
	char c,s[100];
	while (1)
	{
		fscanf(fp,"%c",&c);
		if (c=='#') 
		{
			fgets(s,sizeof s,fp);
			continue;
		}
		fseek(fp,-1,SEEK_CUR);
		break;
	}
} 

int InputNum(int *num)
{
	char s[100];
	fflush(stdin); 
    gets(s);
	if (s[0]=='\0')	return 0;						//接收到换行
    if (sscanf(s,"%d",num)!=1)						//接收到非数字
	{
		printf("输入有误！请重新输入！\n");
		return 0;
	}
	return 1;
}
//从stdin中读入一个数字，返回成功与否 
