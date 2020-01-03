#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N=20+2,M=20+2;
int n,m;
int d[N*M],id[N][M],t[N][M],c[M],p[M];
bool f[M][10000];

void work()
{
	bool flag;
	int now,k,j;
	for (int i=1;i<=m*n;i++)
	{
		now=d[i];
		c[now]++;
		k=p[now]+1;
		while (true)
		{
			while (!f[id[now][c[now]]][k]) k++;
			flag=true;
			for (j=k;j<=k+t[now][c[now]]-1;j ++)
			{
				if (!f[id[now][c[now]]][j])
				{
					flag=false;
					break;
				}
			}
			int tmp=j;
			if (flag)
			{
				for (j=k;j<=k+t[now][c[now]]-1;j ++)
					f[id[now][c[now]]][j]=false;
				p[now]=k+t[now][c[now]]-1;
				break;
			}
			k=tmp;
		}
		
	}
}

int main()
{
	freopen("1314.in","r",stdin);
	scanf("%d %d",&m,&n);
	for (int i=1;i<=n*m;i++) scanf("%d",&d[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&id[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&t[i][j]);
	memset(f,1,sizeof f);	

	work();

	int ans=0;
	for (int i=1;i<=M;i++)
		if (ans<p[i]) ans=p[i];
	printf("%d\n",ans);	
}

//f[id[now][c[now]]][k] 
