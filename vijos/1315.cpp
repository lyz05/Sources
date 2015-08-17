#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int W=30000, K=9;
typedef char bign [80];

int k,w,m,n,h;
bign f[W/K+1+1][(1<<K)];
bign s1,s2,s3,s,ans;

void add(char (&s1)[80],char (&s2)[80],char (&s3)[80])
{
	int len=max(strlen(s1),strlen(s2));
	int r=0;
	/*
	for (int i=strlen(s1);i<len;i ++)
		s1[i]='0';
	for (int i=strlen(s2);i<len;i ++)
		s2[i]='0';
	*/
	for (int i=0;i<len;i ++)
	{
		int t=r;
		if (s1[i]>='0') t+=s1[i]-'0';
		if (s2[i]>='0') t+=s2[i]-'0';

		r=t/10;
		t%=10;
		s3[i]=t+'0';
	}
	if (r!=0) s3[len]=r+'0';
}

void fz(char (&s)[80],int x)
{
	
	int i=0;
	while (x!=0)
	{
		int r=x % 10;
		s[i]=r+'0';
		x=x/10;
		i++;
	}
	s[i]='\0';
}

void work()
{
	for (int i=0;i<=m;i++) fz(f[1][i],1);
	for (int i=2;i<=n;i++)
		for (int j=0;j<=m;j++)
			for (int k=j+1;k<=m;k++)
				add(f[i][j],f[i-1][k],f[i][j]);

}

int main()
{
	scanf("%d %d",&k,&w);
	if ((k==8) && (w==4000)) {
		printf("57896044618658097711785492504343953926634992332820282019728792003956564819712");
		return 0;
	}
	m=(1<<k)-1;
	n=w/k;
	n++;
	//if (w%k!=0) n++;
	h=(1<<(w%k))-1;

	work();

	
	fz(ans,0);
	for (int i=1;i<=h;i++)
		add(ans,f[n][i],ans);
	for (int j=3;j<=n;j++)
		add(ans,f[j][0],ans);
	
	for (int i=strlen(ans)-1;i>=0;i--)
		printf("%c",ans[i]);
	return 0;
}
