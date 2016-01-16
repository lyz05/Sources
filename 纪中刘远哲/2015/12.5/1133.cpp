#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int D = 15,N = 2005;
int a[D][N],f[N],vis[D][N];
int n,ans;

void dfs(int dep,int len,int now)
{
	if (now<=0 || now>N || f[now]<dep) return;
	if (dep==len) 
	{
		f[now] = dep;
		if (now==n) 
			ans = len;
		return;
	}
	a[dep][++ a[dep][0]] = now;
	//vis[dep][now] = 1;
	f[now] = dep;
	int tot = a[dep][0];
	for (int i=1;i<=tot;i ++)
	{
		for (int j=-1;j<=1;j += 2)
		{
			memcpy(a[dep+1],a[dep],sizeof a[dep]);
			dfs(dep+1,len,now+j*a[dep][i]);
		}
	}
}


int main()
{
	//freopen("1133.in","r",stdin);
	freopen("1133.out","w",stdout);

		ans = 1e9+7;
		memset(f,125,sizeof f);
		scanf("%d",&n);
		if (n==0) return 0;
		if (n==1) printf("0\n");
		else
			for (int i=1;i<=D;i ++) 
			{
				a[0][0] = 0;
				dfs(0,i,1);
				if (ans!=1e9+7) 
				{
					printf("%d\n",ans);
					break;
				}
			}
	for (int i=1;i<=1000;i ++) printf("%d,",f[i]);
	return 0;
}

