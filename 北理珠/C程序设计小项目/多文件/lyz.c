#include"function.h"

extern char filenameStu[],filenameC[],filenameS[],filenamePsd[];
extern Cinfo c[CNUM];
extern Sinfo s[SNUM];
extern STU stu[NUM],re[NUM];			//ѧ����Ϣ�����ص�ѧ����Ϣ
extern int para[NUM];
extern int num,cnum,snum;				//ѧ������,ѧԺ�������Ա����� 

//lyz
void menu5();
void menu7();
int ModifyStuinfo(STU x[], int num, int id, char filename[]);
//���ݸ�����ѧ��ѧ���޸ĸ�ѧ������Ϣ
int JudgePsd(char psd[],char filename[]);
//�ж�������ȷ��
int ModifyPsd(char psd[],char filename[]);
//�޸����룬�����޸��Ƿ�ɹ�
char* encodeInp(char *input);
//��������м��� 

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
