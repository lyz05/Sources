#include"function.h"

extern char filenameStu[],filenameC[],filenameS[],filenamePsd[];
extern Cinfo c[CNUM];
extern Sinfo s[SNUM];
extern STU stu[NUM],re[NUM];			//ѧ����Ϣ�����ص�ѧ����Ϣ
extern int para[NUM];
extern int num,cnum,snum;				//ѧ������,ѧԺ�������Ա����� 

void sortStudents(STU *s, int *para, int num,CompareMethod cm);
//��num��ѧ������ָ���ȽϷ�ʽ����
void menu8(); 

//hyh
void menu2();
void menu6();
int sortByName(STU x, STU y);
//������������
int findName(STU x[], int num, char name[], STU re[]); 
//���ݸ�����name����num��x���ҳ�ͬ���������δ�ŵ�re�У����������ҵ�������


void menu2()
{
	if (error()) return;
	sortStudents(stu,para,num,sortByName);
	int i;
	for (i=0;i<num;i ++) printStu(stu[para[i]]);
	menu8();
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

int sortByName(STU x, STU y) {return strcmp(x.name,y.name)>0;}

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
