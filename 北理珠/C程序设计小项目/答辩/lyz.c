#include"function.h"

extern char filenameStu[],filenameC[],filenameS[],filenamePsd[];
extern Cinfo c[CNUM];
extern Sinfo s[SNUM];
extern STU stu[NUM],re[NUM];			//学生信息，返回的学生信息
extern int para[NUM];
extern int num,cnum,snum;				//学生总数,学院总数，性别总数 

//lyz
void menu5();
void menu7();
int ModifyStuinfo(STU x[], int num, int id, char filename[]);
//根据给定的学生学号修改该学生的信息
int JudgePsd(char psd[],char filename[]);
//判断密码正确性
int ModifyPsd(char psd[],char filename[]);
//修改密码，返回修改是否成功
char* encodeInp(char *input);
//对密码进行加密 

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
