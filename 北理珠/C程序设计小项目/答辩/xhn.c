#include"function.h"

extern char filenameStu[],filenameC[],filenameS[],filenamePsd[];
extern Cinfo c[CNUM];
extern Sinfo s[SNUM];
extern STU stu[NUM];			//ѧ����Ϣ�����ص�ѧ����Ϣ
extern int num,cnum,snum;				//ѧ������,ѧԺ�������Ա����� 

//xhn
void menu4();
void menu8();								//�˵���ʾ
void menu0();


void menu4()
{
	if (error()) return;
	puts("********************��ָ��һ��ѧԺ*****************************");
	int i;
	for (i=0;i<cnum;i ++) 
		printf("%d. %s\n",c[i].id,c[i].name);
	puts("***************************************************************");
	while (1)
	{
		int n;
		printf("������ѧԺ����:");
		if (InputNum(&n) == 0) continue; 
		for (i=0;i<num;i ++) 
			if (stu[i].cid==n)
				printStu(stu[i]); 
		break;
	}
	menu8();
}

void menu0()
{
	exit(0);
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

