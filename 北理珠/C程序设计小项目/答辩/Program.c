#include "function.h"
#include "Program.h"

char filenameStu[]="data\\Stu_Info3.txt",filenameC[]="data\\C_Info1.txt",filenameS[]="data\\S_Info2.txt",filenamePsd[]="data\\psd.txt";
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
