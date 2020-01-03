#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 200;

int a[maxn];
long long f[maxn][maxn];
int n,k,x,y;

long long max(long long x , long long y)
{
	if (x > y) return x;
	return y;
}

struct Node
{
	int l,r,fa,size;
}tree[maxn * 2];

void dfs(int x)
{
	if (tree[x].l) dfs(tree[x].l);
	if (tree[x].r) dfs(tree[x].r);
	tree[x].size = tree[tree[x].l].size + tree[tree[x].r].size + 1;
}

void dp(int x)
{
	if (tree[x].l) dp(tree[x].l);
	if (tree[x].r) dp(tree[x].r);
	f[x][0] = 0;
	f[x][1] = a[x];
	for (int i = 2 ; i <= tree[x].size ; i ++)
	{
		int flag = 0;
		if (tree[x].l && tree[x].r)
		{
			for (int j = 0 ; j <= i - 1 ; j ++)
			{
				if (j > tree[tree[x].l].size || i - j - 1 > tree[tree[x].r].size) continue;
				if (flag) f[x][i] = max(f[x][i] , f[tree[x].l][j] + f[tree[x].r][i - j - 1] + a[x]); 
					else f[x][i] = f[tree[x].l][j] + f[tree[x].r][i - j - 1] + a[x] , flag = 1;
			}
		} else
		{
			if (tree[x].l)
			{
				f[x][i] = f[tree[x].l][i - 1] + a[x];
			} else {
				if (tree[x].r)
				{
					f[x][i] = f[tree[x].r][i - 1] + a[x];
				}
			}
		}
	}
}

int main()
{
	
	memset(tree , 0 , sizeof tree);
	
	scanf("%d%d" , &n , &k);
	a[1] = 0;
	for (int i = 1 ;i < n ; i ++) scanf("%d" , &a[i + 1]);
	for (int i = 1 ; i <= n ; i ++)
	{
		scanf("%d%d" , &x , &y);
		tree[i].l = x ; tree[i].r = y;
		tree[x].fa = tree[y].fa = i;
	}
	
	dfs(1);
	
	for (int i = 1 ; i <= n ; i ++) f[i][0] = 0;
	dp(1);
	printf("%I64d" , f[1][k + 1]);
	
	return 0;
}
