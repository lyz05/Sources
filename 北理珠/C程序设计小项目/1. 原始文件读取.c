//FILE *p1,*p2,*p3;
//p1=fopen("C:\steam\C程序设计小项目.rar\data\Stu_Info3.txt","w");
//p2=fopen("C:\steam\C程序设计小项目.rar\data\C_Info1.txt","w");
//p3=fopen("C:\steam\C程序设计小项目.rar\data\S_Info2.txt","w");
#include "main.h"
int inputStu(STU stu[], int num, char filename[])
{
	FILE *p1;
	p1 = fopen(filename,"r");
	char s[100];
	int i=-1,j;
	while (fgets(s,sizeof s,p1)!=NULL)
	{
		if (s[0]=='#') continue;
		//i ++;
		//if (i==-1) continue;
		printf("%s",s);
		for (i=0;i<num;i ++)
		{
			fscanf(p1,"%d %s %d %d",&stu[i].id,stu[i].name,&stu[i].sid,&stu[i].cid);
			printf("%d %s %d %d",stu[i].id,stu[i].name,stu[i].sid,stu[i].cid); 
			for (j=0;j<10;j ++)
			{
				fscanf(p1,"%d",&stu[i].score[j]);
				printf("%d ",stu[i].score[j]);
			}
			printf("\n");
		}
		return;
	}
	
	
	fclose(p1);
	/* 
	int i;
	for(i=0;i<num;i++)
	{
		stu[i].id=p1
		stu[i].name=
		stu[i].sid=
		stu[i].cid=
		stu[i].score=
		stu[i].ave=
		stu[i].nm=
	}
	*/
}
