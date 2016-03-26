#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXN=20+5;
const int oo=2e9;
int n,m,r,c,rb[MAXN],a[MAXN][MAXN],ans;

void dp()
{
	int hc[MAXN][MAXN],zc[MAXN],f[MAXN][MAXN];
	memset(hc,0,sizeof hc);
	memset(zc,0,sizeof zc);
	rb[r+1]=rb[r];
	for (int i=1;i<=m;i++)
		for (int j=1;j<=r;j++)
			zc[i]+=abs(a[rb[j]][i]-a[rb[j+1]][i]);
	for (int i=1;i<=m-1;i++)
		for (int j=i+1;j<=m;j++)
			for (int k=1;k<=r;k++)
				hc[i][j]+=abs(a[rb[k]][i]-a[rb[k]][j]);

	memset(f,0,sizeof f);
	for (int i=1;i<=m;i++) f[1][i]=zc[i];
	for (int i=2;i<=c;i++)
		for (int j=i;j<=m;j++)
		{
			int t=oo;
			for (int k=i-1;k<=j-1;k++)
				t=min(t,f[i-1][k]+hc[k][j]);
			f[i][j]=t+zc[j];
		}
	for (int i=c;i<=m;i++) ans=min(ans,f[c][i]);
}

void dfs(int k,int p)
{
	if (k==r) 
	{
		dp();
		return;
	}
	for (int i=p+1;i<=n;i++)
	{
		rb[k+1]=i;
		dfs(k+1,i);
	}
}

int main()
{
	freopen("1914.in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);

	ans=oo;
	dfs(0,0);

	printf("%d",ans);
	return 0;
}
