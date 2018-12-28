#include"function.h"

extern char filenameStu[],filenameC[],filenameS[],filenamePsd[];
extern Cinfo c[CNUM];
extern Sinfo s[SNUM];
extern STU stu[NUM],re[NUM];			//ѧ����Ϣ�����ص�ѧ����Ϣ
extern int para[NUM];
extern int num,cnum,snum;				//ѧ������,ѧԺ�������Ա����� 

void menu8(); 
//yrf
void menu1();
void menu3();
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
	//			printf("ѧ���ǣ�%d\n �����ǣ�%s\n �Ա��ǣ�%d\n ѧԺ�ǣ�%d\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].college);
	//			printf("��%d�ĳɼ��ǣ�%d\n",j+1,stu[i].score[j]);
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

