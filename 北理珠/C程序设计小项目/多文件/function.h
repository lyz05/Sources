#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>			//��������
#include<io.h>				//�ļ����ڼ��
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


int error();								//δ�����ļ���� 
void init();								//ϵͳ��ʼ��&������ 
void printStu(STU stu);
void seekPos(FILE *fp);
//�����ļ��������ע�� 
void InputPsd(char psd[]);
//�������뺯��
int InputNum(int *num);
//��stdin�ж���һ�����֣����سɹ���� 


