#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>			//�������� 
#include<io.h>				//�ļ����ڼ�� 

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


void menu2();
void menu4();
void menu5();
void menu6();
void menu7();
void menu8();
void menu0();
int error();								//δ�����ļ���� 
void init();								//ϵͳ��ʼ��&������ 
void printStu(STU stu);
void seekPos(FILE *fp);
//�����ļ��������ע�� 


int sortByName(STU x, STU y);
//������������
int findName(STU x[], int num, char name[], STU re[]); 
//���ݸ�����name����num��x���ҳ�ͬ���������δ�ŵ�re�У����������ҵ�������
int ModifyStuinfo(STU x[], int num, int id, char filename[]);
//���ݸ�����ѧ��ѧ���޸ĸ�ѧ������Ϣ
int JudgePsd(char psd[]);
//�ж�������ȷ��
int ModifyPsd(char psd[],char filename[]);
//�޸����룬�����޸��Ƿ�ɹ�
char* encodeInp(char *input);
//��������м��� 
void InputPsd(char psd[]);
//�������뺯�� 


//yrf
void menu1();
int inputStu(STU stu[], int *num, char filename[]);    
//���ļ���filename��num��ѧ����Ϣ������stu����ͬʱ����ƽ���ɼ�,�ɹ������棬ʧ�ܷ��ؼ� 
int inputCinfo(Cinfo x[], int *num, char filename[]);   
//���ļ���filename��num��ѧԺ��Ϣ������x,�ɹ������棬ʧ�ܷ��ؼ�
int inputSinfo(Sinfo x[], int *num, char filename[]);
//���ļ���filename��num���Ա���Ϣ������x,�ɹ������棬ʧ�ܷ��ؼ�
void menu3();
int sortByAve(STU x, STU y);
//����ƽ���ɼ�����
void sortStudents(STU *s, int *para, int num,CompareMethod cm);
//��num��ѧ������ָ���ȽϷ�ʽ����

