
int inputStu(STU stu[], int *num, char filename[]);  
int inputCinfo(Cinfo x[], int *num, char filename[]);   
//从文件名filename读num个学院信息到数组x,成功返回真，失败返回假
int inputSinfo(Sinfo x[], int *num, char filename[]);
//从文件名filename读num个性别信息到数组x,成功返回真，失败返回假
void sortStudents(STU *s, int *para, int num);
int main()
{
	
	STU a[100];Cinfo c[100];Sinfo d[100];
	int m,n,f,u,y;
	inputStu(a,&m,"Stu_Info3");
	inputCinfo(c,&n,"S_Info2");
	inputSinfo(d,&f,"C_Info1");
	void sortStudents(STU *s, int *para, int num);
	return 0;
}
int inputStu(STU stu[], int *num, char filename[])
{
	FILE *fp;
	if((fp=fopen("Stu_Info3.txt","r"))==NULL)
	{
		printf("Can't not open this file");
		return 0;
	} 
	if(ferror(fp))
		printf("This file has error");
	char s[100];
	while (1)
	{
		int n; 
		fgets(s,sizeof (s),fp);
		if(s[0]=='#')
			continue;
		sscanf(s,"%d",&n);
		//printf("%d\n",n);
		int i,j;
		for(i=0;i<n;i++)
		{
			fscanf(fp,"%d %s %d %d",&stu[i].num,stu[i].name,&stu[i].sex,&stu[i].college);
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
	//			printf("学号是：%d\n 姓名是：%s\n 性别是：%d\n 学院是：%d\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].college);
	//			printf("第%d的成绩是：%d\n",j+1,stu[i].score[j]);
	//		}
			break;		
	}
	fclose(fp);	
}
int inputCinfo(Cinfo x[], int *num, char filename[])
{
	FILE *fp;
	fp=fopen("S_Info2.txt","r");
	char b[100];
	while(1)
	{
		fgets(b,sizeof (b),fp);
		if(b[0]=='#')
			continue;
		int i,h;
		sscanf(b,"%d",&h);
		for(i=0;i<h;i++)
		{
			fscanf(fp,"%d %s",&x[i].id,x[i].name);
	//		printf("%d\n %s\n",x[i].id,x[i].name);
		}
		break;
	}
}
int inputSinfo(Sinfo x[], int *num, char filename[])
{
	FILE *fp;
	fp=fopen("C_Info1.txt","r");
	char p[100];
	while(1)
	{
		fgets(p,sizeof(p),fp);
		if(p[0]=='#')
			continue;
		int i,q;
		sscanf(p,"%d",&q);	
		for(i=0;i<q;i++)
		{
			fscanf(fp,"%d %s",&x[i].id,x[i].name);
		//	printf("%d %s\n",x[i].id,x[i].name);
		}
		break;
	}
}
void sortStudents(STU s[], int *para, int num)
{	
	int i,j,tmp;
	for(i=0;i<num;i++) 
		para[i]=i;
	for(i=0;i<num;i++)
	    for(j=i+1;j<num;j++)
	    	if(s[para[i]].ave<s[para[j].ave)
			{  
				tmp = para[i];
				para[i] = para[j];
				para[j] = tmp;	
			}
}

void sortStudents(STU s[] ,int num)
{	
	int i,j,tmp;
	for(i=0;i<num;i++)
	    for(j=i+1;j<num;j++)
	    	if(s[i].ave<s[j].ave)
			{  
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;	
			}	
}



	
