#include <cstdio>
#include <cmath>
#include <algorithm>

const int N=10+1,M=100000;
int a[M][N],cnt[M];
int n,k,r;

int gcd(int x,int y)
{
	if (y==0) return x;
	else return gcd(y,x % y);
}

bool judge(int x)
{
	for (int i=1;i<n;i++)
	{
		if (gcd(a[x][i],a[x][i+1])==1 || abs(a[x][i]-a[x][i+1])<r)
			return 0;
	}
	return 1;
}

void print(int x)
{
	for (int i=1;i<=n;i++) printf("%d ",&a[x][i]);
	printf("\n");
}

void work(int x)
{
	int l=0;r=0;
	while (l<=r) 
	{
		if (judge(l)) print;
		for (int i=1;i<=n;i++)
		{
			if (a[l][i]+1<=k){
				r++;
				for (int j=1;j<=n;j++)
					a[r][j]=a[l][j];
				a[r][i]++;
			}
			if (a[l][i]-1>=1){
				r++;
				for (int j=1;j<=n;j++)
					a[r][j]=a[l][j];
				a[r][i]--;
			}
		}
		l++;
	}
}

int main()
{
	scanf("%d%d%d",&n,&k,&r);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[0][i]);
	cnt[0]=0;
	work(0);
	return 0;
}
