#include<cstdio>
#include<cstring> 
using namespace std;

const int N = 105;
int tot;

void add(char *s1,char *s2,int *s3)
{
	//int i=strlen(s1),strlen(s2));
	int jw = 0,i,j;
	tot = -1;
	for (i=strlen(s1)-1,j=strlen(s2)-1;i>=0 && j>=0;i --,j --)
	{
		int now = s1[i]-'0'+s2[j]-'0'+jw; 
		s3[++ tot] = now%10;
		jw = now/10;
	}
	if (i==-1 && j==-1) 
	{
		if (jw) s3[++ tot] = jw,jw = 0;
	}
	else
	if (i==-1)
		for (int k=j;k>=0;k --) 
		{
			int now = s2[k]-'0'+jw;
			s3[++ tot] = now%10;
			jw=now/10;
		}
	else
	if (j==-1)
		for (int k=i;k>=0;k --) 
		{
			int now = s1[k]-'0'+jw;
			s3[++ tot] = now%10;
			jw=now/10;
		}
	if (jw) s3[++ tot] = jw;
}		

int main()
{
	//freopen("1001.in","r",stdin);
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i ++)
	{
		char s1[N],s2[N];
		int s3[N]={};
		scanf("%s %s",s1,s2);
		add(s1,s2,s3);
		printf("Case %d:\n",i);
		printf("%s + %s = ",s1,s2);
		for (int j=tot;j>=0;j --) printf("%d",s3[j]);
		if (i!=T) printf("\n\n"); else printf("\n");
	}
	return 0;
} 
//    11223344556677
//998877665544332211
//
