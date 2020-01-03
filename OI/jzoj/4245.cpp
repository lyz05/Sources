#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
typedef double LB;
const int N = 4,M = 100+5;
int n,m,k;
int a[4][M],b[N],f[M*2000+5];
LB ans,maxx,sum[M];

bool cmp(int x,int y)
{return x>y;}

int main()
{
	freopen("4245.in","r",stdin);
	//freopen("2.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i ++) scanf("%d",b + i);
	for (int i=1;i<=m;i ++)
	{
		int type,val;
		scanf("%d%d",&type,&val);
		a[type][++ a[type][0]] = val; 
	}
	sort(a[2] + 1,a[2] + 1 + a[2][0],cmp);
	sort(a[3] + 1,a[3] + 1 + a[3][0],cmp);

	ans = 0;
	if (n==1)
	{
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
	if (n==2)
	{
		sum[0] = log(1);
		for (int i=1;i<=a[3][0];i ++)
			sum[i] = sum[i-1]+log(a[3][i]);
		if (b[1]>b[2]) swap(b[1],b[2]);
		
		for (int kk=0;kk<2;kk ++)
		{
		memset(f,0,sizeof f);	
		int x,y;
		if (kk==0) 
		{
			x = b[1]; y = b[2]; 

		}else 
		       if (a[1][0]) 
		       {
			       x = a[1][1]; y = b[2];
			       k --;
		       }else break;
		f[x] = y;
		ans = max(ans,sum[k]+log(x)+log(y));
		for (int i=1;i<=min(a[2][0],k);i ++)
		{
			maxx = 0;
			for (int j=x;j>=0;j --)
			{
				//if (f[j]==0) continue;
				if (j+a[2][i]<=M*2000)
				{
					f[j+a[2][i]] = max(f[j],f[j+a[2][i]]);
					maxx = max(maxx,log(f[j+a[2][i]])+log(j+a[2][i]));
				}
				f[j] = max(f[j]+a[2][i],f[j]);
				if (j!=0) maxx = max(log(f[j])+log(j),maxx);
			}
			x += a[2][i];
			ans = max(maxx+sum[k-i],ans);
		}
		}
	}
	printf("%.3f\n",ans);
	return 0;
}
