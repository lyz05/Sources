#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N=1000+5;
int n,m,A,B,a[N][3],b[N][3],sum[3],ans;

void calc(int x,int y)
{
	int cost = 0;
	for (int i=1;i<=A;i++)
		cost += (x-a[i][1])*(x-a[i][1]) + (y-a[i][2])*(y-a[i][2]);
	int costb = 1e8;
	for (int i=1;i<=B;i++)
	{
		int tmp=abs(x-b[i][1])+abs(y-b[i][2]);
		costb = min(costb,tmp);
	}
	cost += costb;
	ans = min(ans,cost);
}

int main()
{
	freopen("3.in","r",stdin);
	int t;
	scanf("%d",&t);
	for (int cnt=1;cnt<=t;cnt++)
	{
		sum[1] = 0;sum[2] = 0;
		scanf("%d%d%d%d",&n,&m,&A,&B);
		for (int i=1;i<=A;i++)
		{
			scanf("%d%d",&a[i][1],&a[i][2]);
			sum[1] += a[i][1],sum[2] += a[i][2];
		}
		for (int i=1;i<=B;i++) 
			scanf("%d%d",&b[i][1],&b[i][2]);
		sum[1] /= A;sum[2] /= A;

		ans = 1e8;
		calc(sum[1],sum[2]);calc(sum[1]+1,sum[2]);
		calc(sum[1]+1,sum[2]+1);calc(sum[1],sum[2]+1);

		printf("Case #%d: %d\n",cnt,ans);
	}
	return 0;
}
