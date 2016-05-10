#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 200 , M = 200 , oo = 1e9+7;
struct node1
{int lv,sz,num;}a[N];
struct node2
{int sz,w,num;}b[M];

int ans,tmp,tot;
int n,m,p;

void dfs1(int dep,int love)
{
	if (tmp>=ans) return;
	if (love>=p)
	{
		ans = tmp;
		return;
	}
	if (dep>n) return;
	for (int i=a[dep].num;i>=0;i --)
	{
		love += i*a[dep].lv;
		tmp += i*a[dep].sz;
			dfs1(dep+1,love);
		tmp -= i*a[dep].sz;
		love -= i*a[dep].lv;
	}
}
void dfs2(int dep,int size)
{
	if (tmp>=ans) return;
	if (size>=tot)
	{
		ans = tmp;
		return;
	}
	if (dep>m) return;
	for (int i=b[dep].num;i>=0;i --)
	{
		size += i*b[dep].sz;
		tmp += i*b[dep].w;
			dfs2(dep+1,size);
		tmp -= i*b[dep].w;
		size -= i*b[dep].sz;
	}
}
int main()
{
	freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		scanf("%d%d%d",&n,&m,&p);
		for (int i=1;i<=n;i ++)
		{
			scanf("%d%d%d",&a[i].lv,&a[i].sz,&a[i].num);
		}
		for (int i=1;i<=m;i ++)
		{
			scanf("%d%d%d",&b[i].sz,&b[i].w,&b[i].num);
		}

		ans = oo;tmp = 0;int love = 0;
		dfs1(1,love);
		tot = ans;
		ans = oo;tmp = 0;int size = 0;
		dfs2(1,size);
		if (ans == oo) puts("TAT");else printf("%d\n",ans);
	}

	return 0;
}
