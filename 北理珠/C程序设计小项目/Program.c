#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>			//��������
#include<io.h>			//�ļ����ڼ��
#define NUM 100				//ѧ�����ֵ
#define CNUM 10				//ѧԺ���ֵ
#define SNUM 3				//�Ա���Ϣ���ֵ

typedef struct c{
	int id;
	char name[32];
}Cinfo;
//ѧԺ��Ϣ
typedef struct gd{
	int id;
	char name[16];
}Sinfo;
//�Ա���Ϣ
typedef struct stu{
	int id;
	char name[16];
	int sid;				//�Ա����
	int cid;				//ѧԺ����
	int score[10];			//10�ųɼ�
	float ave;				//ƽ���ɼ� 
	//int nm;				//�ɼ�����
}STU;
//ѧ����Ϣ 

typedef int (*CompareMethod)(STU x,STU y);
//CompareMethod �ȽϷ�ʽ����ָ��

void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void menu6();
void menu7();
void menu8();								//�˵���ʾ
void menu0();
//Ŀ¼��Ϣ
int error();								//δ�����ļ���� 
void init();								//ϵͳ��ʼ��&������ 
void printStu(STU stu);
void seekPos(FILE *fp);
//�����ļ��������ע�� 
int inputStu(STU stu[], int *num, char filename[]);    
//���ļ���filename��num��ѧ����Ϣ������stu����ͬʱ����ƽ���ɼ�,�ɹ������棬ʧ�ܷ��ؼ� 
int inputCinfo(Cinfo x[], int *num, char filename[]);   
//���ļ���filename��num��ѧԺ��Ϣ������x,�ɹ������棬ʧ�ܷ��ؼ�
int inputSinfo(Sinfo x[], int *num, char filename[]);
//���ļ���filename��num���Ա���Ϣ������x,�ɹ������棬ʧ�ܷ��ؼ�
void sortStudents(STU *s, int *para, int num,CompareMethod cm);
//��num��ѧ������ָ���ȽϷ�ʽ����
int sortByAve(STU x, STU y);
//����ƽ���ɼ�����
int sortByName(STU x, STU y);
//������������
int findName(STU x[], int num, char name[], STU re[]); 
//���ݸ�����name����num��x���ҳ�ͬ���������δ�ŵ�re�У����������ҵ�������
int ModifyStuinfo(STU x[], int num, int id, char filename[]);
//���ݸ�����ѧ��ѧ���޸ĸ�ѧ������Ϣ
int JudgePsd(char psd[],char filename[]);
//�ж�������ȷ��
int ModifyPsd(char psd[],char filename[]);
//�޸����룬�����޸��Ƿ�ɹ�
char* encodeInp(char *input);
//��������м��� 
void InputPsd(char psd[]);
//�������뺯��
int InputNum(int *num);
//��stdin�ж���һ�����֣����سɹ���� 

char filenameStu[]="data1\\Stu_Info3.txt",filenameC[]="data1\\C_Info1.txt",filenameS[]="data1\\S_Info2.txt",filenamePsd[]="data1\\psd.txt";
Cinfo c[CNUM];
Sinfo s[SNUM];
STU stu[NUM],re[NUM];						//ѧ����Ϣ�����ص�ѧ����Ϣ
int para[NUM];
int num = 0,cnum = 0,snum = 0;				//ѧ������,ѧԺ�������Ա����� 

int main()
{
	init();									//������ 
	menu8();
	int n;
	while (1)
	{
		printf("������Ҫ���е�ģ��:");
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
			default:printf("����������������������\n");
		}
	}
	return 0;
} 

int error()
{
	if (num==0) printf("�����㻹δ���������Ϣ�����Ƚ���ԭʼ�ļ���ȡ\n");
	return (num==0);
} 

void menu0()
{
	exit(0);
}

void menu1()
{
	if (inputStu(stu,&num,filenameStu))
		printf("����ѧ����Ϣ�ɹ���������%d����Ϣ\n",num);
	else
		printf("���󣺶���ѧ����Ϣʧ��\n");
	if (inputCinfo(c,&cnum,filenameC))
		printf("����ѧԺ��Ϣ�ɹ���������%d����Ϣ\n",cnum);
	else
		printf("���󣺶���ѧԺ��Ϣʧ��\n"); 
	if (inputSinfo(s,&snum,filenameS)) 
		printf("�����Ա���Ϣ�ɹ���������%d����Ϣ\n",snum);
	else
		printf("���󣺶����Ա���Ϣʧ��\n");
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
	puts("********************��ָ��һ��ѧԺ*****************************");
	int i;
	for (i=0;i<cnum;i ++) printf("%d. %s\n",c[i].id,c[i].name);
	puts("***************************************************************");
	while (1)
	{
		int n;
		printf("������ѧԺ����:");
		if (!InputNum(&n)) continue;
		for (i=0;i<cnum && c[i].id!=n;i ++);
		if (i==cnum)									//δ��ѧԺ�ṹ�����ҵ���Ӧ������ 
		{
			printf("����������������������\n");
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
	printf("������ѧ��ѧ�ţ�");
	scanf("%d",&id);
	if (ModifyStuinfo(stu,num,id,filenameStu))
		printf("�޸�ѧ����Ϣ�ɹ���\n");
	else
		printf("�޸�ѧ����Ϣʧ�ܣ�\n");
}

void menu6()
{
	if (error()) return;
	char s[16];
	printf("������ѧ����������ȫƥ�䣩��");
	scanf("%s",s);
	int tot = findName(stu,num,s,re);
	if (tot==0) 
	{
		printf("����δ�ҵ���ѧ����\n");
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
		printf("����������룺");
		InputPsd(old);
		if (!JudgePsd(old,filenamePsd))
		{
			printf("�����������\n");
			return; 
		}
	}
	printf("�����������룺");
	InputPsd(new[0]);
	printf("���ٴ����������룺");
	InputPsd(new[1]);
	if (strcmp(new[0],new[1])!=0)
	{
		printf("������������������벻ͬ\n");
		return;
	}
	if (ModifyPsd(new[0],filenamePsd))
		printf("�޸�����ɹ���\n");
	else
		printf("�޸�����ʧ�ܣ�\n");
}

void init()
{
	if (!JudgePsd("",filenamePsd)) 
	{
		char s[100];
		while (1)
		{
			printf("����������������ϵͳ��");
			//gets(s);
			InputPsd(s);
			if (s[0]=='\0') continue;
			if (!JudgePsd(s,filenamePsd))
			{
				printf("�����������\n");
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
	printf("ѧ�ţ�%d\t������%s\t�Ա�%s\tѧԺ��%s\n",stu.id,stu.name,sname,cname);
	printf("��ѧ����%d�ſγɼ���Ϣ��\n",10);
	for (i=0;i<10;i ++)	printf("%d\t",stu.score[i]);
	printf("\n");
	printf("ƽ���֣�%f\n\n",stu.ave);
}

void menu8()
{
	puts("********************ѧ���ɼ�����ϵͳ***************************");
	puts("1. ԭʼ�ļ���ȡ");
	puts("2. �������������");
	puts("3. ��ƽ���ɼ��������");
	puts("4. �������ѧԺѧ��");
	puts("5. �޸ĸ���ѧ���ɼ���Ϣ���޸ĺ����Ϣ����������ļ���");
	puts("6. ��������ѯѧ�������");
	puts("7. �޸�ϵͳ����");
	puts("8. ��ʾ�˵�");
	puts("0. ����ϵͳ");
	puts("***************************************************************"); 
} 

int inputStu(STU stu[], int *num, char filename[])
{
	FILE *fp;
	if ((fp = fopen(filename,"r"))==NULL) return 0;
	seekPos(fp);
		
	int i,j;
	//������дλ�� 
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
	//ƽ�������ʼ�� 
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
}//������ 

int ModifyStuinfo(STU x[], int num, int id, char filename[])
{
	int flag = 0;
	FILE *fp;
	if ((fp = fopen(filename,"r+"))==NULL) return 0;
	seekPos(fp);
	char s[500];
	
	//fprintf(fp,"%d",20);
	fgets(s,sizeof s,fp);									//�������� 
	fseek(fp,0,SEEK_CUR);									//תΪд���� 
	int i,j,n;
	for (i=0;i<num;i ++)
	{
		if (x[i].id == id)
		{
			printf("�޸�ǰ��\n");
			printStu(x[i]);
			while (1)
			{
				printf("��������Ҫ�޸ĳɼ��ı��(1~10)��");	
				if (scanf("%d",&n)!=1 || n>10 || n<1) 
    			{
					while(getchar()!='\n');					//������������� 
					printf("�����������������룡\n");
					continue;
				}
				break; 
			}
			printf("�������³ɼ���");
			int score;
			scanf("%d",&score);
			x[i].score[n-1] = score;
			{
				for (j=0,x[i].ave=0;j<10;j ++) x[i].ave += x[i].score[j];
				x[i].ave /= 10;
			}//����ƽ���� 	
			printf("�޸ĺ�\n");
			printStu(x[i]);
			flag = 1;
		}
		//�ļ�����
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
		printf("�Ҳ���ѧ��Ϊ%d��ѧ��\n",id);
	return flag;
}

int JudgePsd(char psd[],char filename[])
{
	char data[100]={}; 
	char *encode = encodeInp(psd);
	if (access(filename,F_OK)==-1) return 1;	//������ 
	FILE *fp = fopen(filename,"r");
	if (fp==NULL)
	{
		printf("���󣺴��ļ�ʧ�ܣ�\n");
		return 0;
	}
	fgets(data,sizeof data,fp);
	if (fclose(fp)==EOF) return 0;
	return (strcmp(data,encode)==0);
}

int ModifyPsd(char psd[],char filename[])
{
	char *encode = encodeInp(psd);
	//if (access(filename,F_OK)==-1) return 1;	//������ 
	FILE *fp = fopen(filename,"w");
	if (fp==NULL)
	{
		printf("���󣺴��ļ�ʧ�ܣ�\n");
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
	if (s[0]=='\0')	return 0;						//���յ�����
    if (sscanf(s,"%d",num)!=1)						//���յ�������
	{
		printf("�����������������룡\n");
		return 0;
	}
	return 1;
}
//��stdin�ж���һ�����֣����سɹ���� 
