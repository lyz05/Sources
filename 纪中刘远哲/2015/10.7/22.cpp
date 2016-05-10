#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
typedef double LB;
const int N = 4,M = 100+5;
int n,m,k;
int a[4][M],b[N];
LB ans;

bool cmp(int x,int y)
{return x>y;}

int main()
{
	freopen("2.in","r",stdin);
	//freopen("2.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i ++) scanf("%d",b + i);
	for (int i=1;i<=m;i ++)
	{
		int type,val;
		scanf("%d%d",&type,&val);
		a[type][++ a[type][0]] = val; 
	}
	if (n==1)
	{
		sort(a[2] + 1,a[2] + 1 + a[2][0],cmp);
		sort(a[3] + 1,a[3] + 1 + a[3][0],cmp);
		LB sum[4] = {0,0,0,0};
		for (int i=0;i<=k;i ++)
		{
			sum[2] += (i==0)?0:a[2][i];
			sum[3] = 0; 
			for (int j=0;j<=k-i;j ++)
			{
				sum[3] += log((j==0)?1:a[3][j]);
				LB tmp = log(b[1]+sum[2])+sum[3];
				if (tmp>ans) 
					ans = tmp;
			}
		}
		if (a[1][0]) 
			ans = max(ans,(LB)log(a[1][1]));
	}
	printf("%.3f\n",ans);
	return 0;
}

