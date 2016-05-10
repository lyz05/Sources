#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 2*1e5;
struct node
{
	int x,y;
} a,b;

int n,m;
LL dis[3][N],id[3][N];
int ans;
bool flag[N];

LL sqr(int x) {
	return (LL)x*x;
}
LL dist(int x1,int y1,int x2,int y2)
{
	return sqr(x1-x2)+sqr(y1-y2);
}

bool cmp1(LL x,LL y)
{
	return dis[1][x]<dis[1][y];
}

bool cmp2(LL x,LL y)
{
	return dis[2][x]<dis[2][y];
}

int main()
{
	freopen("supply.in","r",stdin);
	freopen("supply.out","w",stdout);

	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
	for (int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		dis[1][i] = dist(x,y,a.x,a.y);
		dis[2][i] = dist(x,y,b.x,b.y);
		id[1][i] = id[2][i] = i; 
	}
	sort(id[1]+1,id[1]+1+n,cmp1);
	sort(id[2]+1,id[2]+1+n,cmp2);
	
	for (int i=1;i<=m;i++)
	{
		ans = 0;
		memset(flag,0,sizeof flag);
		LL r1,r2;
		scanf("%I64d%I64d",&r1,&r2);
		r1 = sqr(r1); r2 = sqr(r2);
		for (int j=1;j<=n;j++)
			if (dis[1][id[1][j]]>r1) break;
			else if (!flag[id[1][j]])
		       	{
				ans ++;
				flag[id[i][j]] = 1;
			}
		for (int j=1;j<=n;j++)
			if (dis[2][id[2][j]]>r2) break;
			else if (!flag[id[2][j]])
		       	{
				ans ++;
				flag[id[i][j]] = 1;
			}
		printf("%d\n",ans);
	}
	return 0;
}
