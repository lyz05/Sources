#include <cstdio>
#include <cstring>

using namespace std;

const int N=32;
int n,a[N];
long long f[N][N][2];
	
void work()
{
	for (int i=1;i<=n;i++)
	{
		f[i][i][0] = a[i];
		f[i][i][1] = i;
		f[i][i-1][0]=1;
		f[i+1][i][0]=1;
	}
	for (int i=n;i>0;i--)
	{
		for (int j=i+1;j<=n;j++)
		{
			for (int k=i;k<=j;k++)
			{
				int tmp=f[i][k-1][0]*f[k+1][j][0]+a[k];
				if (tmp>f[i][j][0])
				{
					f[i][j][0]=tmp;
					f[i][j][1]=k;
				}
			}
		}
	}
}

void visit(int l,int r)
{
	int m=f[l][r][1];
	printf("%d ",m);
	if (l<m) visit(l,m-1);
	if (m<r) visit(m+1,r);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(f,0,sizeof f);
	work();
	printf("%d\n",f[1][n][0]);
	visit(1,n);
	printf("\n");
	return 0;
}
