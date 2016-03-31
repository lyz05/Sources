#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

const int N = 1005;
int map[N][N],col[N],f[N],a[N];
int n;
stack <int> T[3];

void fail()
{
	printf("0");
	exit(0);
}

void color(int x,int c)
{
	col[x] = c;
	for (int j=1;j<=n;j ++) 
		if (map[x][j])
		{
			if (col[j]==c) fail();
			if (!col[j]) color(j,3-c);
		}
}

void work()
{
	f[n+1] = 1e9+7;
	for (int i=n;i;i --) f[i] = min(f[i+1],a[i]);
	for (int i=1;i<=n;i ++)
		for (int j=i+1;j<=n;j ++)
			if (a[i]<a[j] && f[j+1]<a[i]) 
				map[i][j]=map[j][i] = 1;
	for (int i=1;i<=n;i ++)
		if (!col[i]) color(i,1);
}

void print()
{
	int now = 1,c;
	for (int i=1;i<=n;i ++)
	{
		c = col[i];
		T[c].push(a[i]);
		if (c==1) printf("a "); else printf("c ");
		while ((!T[1].empty() && T[1].top()==now) || (!T[2].empty() && T[2].top()==now))
		{
			if (!T[1].empty() && T[1].top()==now)
		       	{T[1].pop();printf("b ");now ++;}
			if (!T[2].empty() && T[2].top()==now)
		       	{T[2].pop();printf("d ");now ++;}
		}
	}
	puts("");
}

int main()
{
	freopen("1605.in","r",stdin);
	//freopen("1605.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i]);
	work();
	print();
	return 0;
}
