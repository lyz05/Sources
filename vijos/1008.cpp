#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=50000+5;
int a[N][2],b[N],n,ans;

void work()
{
	int t=0;
	memset(a,0,sizeof a);
	for (int i=1;i<=n;i++)
	{
		a[(b[i]-i+n)%n][1]++;
	}
	for (int i=0;i<=n;i++)
		t=max(a[i][1],t);
	ans=min(ans,n-t);
}

int main()
{
	freopen("1008.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	b[1]=1;
	b[2]=a[1][0];
	int t1=b[1],t2=b[2];
	for (int i=3;i<=n;t1=t2,t2=b[i],i++)
	{
		if (a[t2][0]==t1) b[i]=a[t2][1];
		else
		if (a[t2][1]==t1) b[i]=a[t2][0];
		else
		{
			printf("-1");
			return 0;
		}
	}
	if (b[n]!=a[1][1]) 
	{
		printf("-1");
		return 0;
	}

	ans=N;
	work();
	for (int i=1;i<=n/2;i++)
		swap(b[i],b[n-i+1]);
	work();
	printf("%d\n",ans);
}
