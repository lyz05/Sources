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
	//ƽ�������ʼ�� 
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
}//	������
