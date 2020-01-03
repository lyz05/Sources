#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 15;
char ch[N][N][5];
int id[100],num[N];
bool exist[100],vis[N];
int n,n2;

void print()
{
	for (int i=2;i<=n;i ++)
		printf("%s=%d ",ch[1][i],num[id[(int)ch[1][i][0]]]);
	printf("\n%d\n",n2);
	exit(0);
}

bool judge()
{
	for (int i=2;i<=n;i ++)
	for (int j=2;j<=n;j ++)
	{
		int a = num[id[(int)ch[i][1][0]]],
		    b = num[id[(int)ch[1][j][0]]],
		    c = 0;
		if (strlen(ch[i][j])==2) c = num[id[(int)ch[i][j][0]]]*n2+num[id[(int)ch[i][j][1]]];
		else c = num[id[(int)ch[i][j][0]]];
		if (a+b!=c) return 0;
	}
	return 1;
}

void dfs(int dep)
{
	if (dep>n2)
	{
		if (judge()) print();
	}
	for (int i=0;i<n2;i ++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		num[dep] = i;	
		dfs(dep+1);
		num[dep] = 0;
		vis[i] = 0;
	}
}



int main()
{
	freopen("1596.in","r",stdin);
	//freopen("1596.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=n;j ++)
	{
		scanf("%s",ch[i][j]);
		if (i==1 && j==1) continue;
		for (int k=0;k<strlen(ch[i][j]);k ++) 
			if (!exist[(int)ch[i][j][k]]) 
				exist[(int)ch[i][j][k]] = 1,
				id[(int)ch[i][j][k]] = ++ n2;
	}
	dfs(1);
	printf("Wrong!\n");
	return 0;
}
