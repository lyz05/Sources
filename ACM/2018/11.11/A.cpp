#include<cstdio>
#include<cstring>
using namespace std;

const int N = 8+3;
int n,k,ans,cnt;
char map[N][N];
bool f[N];

void dfs(int dep)
{
	if (k==cnt)
	{
		ans ++;
		return;
	}
	if (dep>=n) return;
	for (int j=0;j<n;j ++)
		if (!f[j] && map[dep][j]=='#')
		{
			f[j] = 1;
			cnt ++;
			dfs(dep + 1);
			cnt --;
			f[j] = 0;
		}
	dfs(dep + 1);
}

int main()
{
	freopen("A.in","r",stdin);
	while(1)
	{
		scanf("%d%d\n",&n,&k);
		if (n==-1 && k==-1) break;
		for (int i=0;i<n;i ++)
		{
			for (int j=0;j<n;j ++)
				scanf("%c",&map[i][j]);
			getchar();
		}
		memset(f,0,sizeof f);
		ans = 0;cnt = 0;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}
