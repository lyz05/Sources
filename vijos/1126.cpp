#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;

const int oo=1e9-1,N=50+2,K=4+2;

int n,m,ans=oo;
int x[N],y[N],f[N][N][K];

int High(int i,int j)
{
	int maxh=0,minh=oo;
	for (int tmp=i;tmp<=j;tmp++)
	{
		maxh=max(maxh,y[tmp]);
		minh=min(minh,y[tmp]);
	}
	return maxh-minh;
}

int work()
{
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			if (x[i]>x[j])
			{
				swap(x[i],x[j]);
				swap(y[i],y[j]);
			}else 
			if (x[i]==x[j] && y[i]>y[j])
				swap(y[i],y[j]);
		}

	memset(f,124,sizeof f);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			f[i][j][1]=(x[j]-x[i])*High(i,j);
	for(int i=1;i<=n;i++)
		for(int k=1;k<=m;k++)
			f[i][i][k]=0;
	for (int k=2;k<=m;k++)
		for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		for (int l=i+1;l<=j;l++)
		f[i][j][k]=min(f[i][j][k],f[i][l-1][k-1]+(x[j]-x[l])*High(l,j));
	ans=min(ans,f[1][n][m]);

}
//July 8-14 15-31
int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	
	work();
	for (int i=1;i<=n;i++)
		swap(x[i],y[i]);
	
	work();

	printf("%d\n",ans);
	return 0;
}
