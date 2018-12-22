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

int sortByAve(STU x, STU y) {return x.ave < y.ave;}

