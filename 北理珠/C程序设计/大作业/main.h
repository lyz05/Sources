#include<stdio.h>
#include<string.h>
#ifndef _COMMON
#define _COMMON
typedef struct c{
	int id;
	char name[32];
}Cinfo;
Cinfo c[10];
typedef struct gd{
	int id;
	char name[16];
}Sinfo;
Sinfo s[3];
typedef struct stu{
	int id;
	char name[16];
	int sid;//�Ա����
	int cid;//ѧԺ����
	int score[10];//10�ųɼ�
	float ave;//ƽ��
	int nm;//�ɼ����� 
}STU;
STU stu[100];

int inputStu(STU stu[], int num, char filename[]);
#endif
