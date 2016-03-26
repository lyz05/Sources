#include <cstdio>
#include <algorithm>
#include <cstring>

const int M=100+5,L=100*100+5;

using namespace std;

int a[M],f[L],stone[L],ans;
int l,s,t,m;

void work()
{
	int d=0,k=s*t,tmp;
	for (int i=1;i<=m+1;i++)
	{
		tmp=a[i]-a[i-1]-d;
		if (tmp>k) d+=tmp-k;
		a[i]=a[i]-d;
		stone[a[i]]=1;
	}
	stone[a[m+1]]=0;
	
	memset(f,127,sizeof f);
	f[0]=0;
	for (int i=1;i<=a[m+1]+t-1;i++)
	{
		for (int j=s;j<=t;j++)
			if (i>=j) f[i]=min(f[i],f[i-j]);
		f[i]+=stone[i];
	}
	int ans=1e9;
	for (int i=a[m+1];i<=a[m+1]+t-1;i++)
		ans=min(ans,f[i]);
	printf("%d\n",ans);
}

int main()
{
	ans=0;
	scanf("%d",&l);
	scanf("%d%d%d",&s,&t,&m);
	a[0]=0;a[m+1]=l;
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	sort(a,a+1+m);
	if (s==t) 
	{
		for (int i=1;i<=m;i++)
			if (a[i]%s==0) ans++;
		printf("%d\n",ans);
	} else work();

	return 0;
}
