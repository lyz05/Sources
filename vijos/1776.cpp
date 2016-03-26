#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 20005,M = 100005;
struct node1
{
	int y,next;
} h[2*M];
struct node
{
	int x,y,z;
} a[M];
int n,m,tot,ans,col[N],e[N];
bool flag;

bool cmp(node A,node B)
{
	return A.z<B.z;
}

void add(int x,int y)
{
	h[++ tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

void make(int limit)
{
	//if (limit==0) limit = 1;
	for (int i=limit+1;i<=m;i ++) 
	{
		add(a[i].x,a[i].y);
		add(a[i].y,a[i].x);
	}
}

void dfs(int x)
{
	if (!flag) return;
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y;
		if (col[y]==-1)
		{
			col[y] = col[x]^1;
			dfs(y);
		} else if (col[y]==col[x]) 
		{
			flag = 0;
			return;
		}
	}
}

int main()
{
	freopen("1776.in","r",stdin);
	//freopen("1776.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+1+m,cmp);
	
	int l = 0,r = m;
	while (l<=r)
	{
		int mid = (l+r)>>1;
		flag = 1;tot = 0;
		memset(e,0,sizeof e);
		memset(col,-1,sizeof col);
		make(mid);
		for (int i=1;i<=n;i ++)
		{
			if (col[i]==-1)
			{
				col[i] = 0;
				dfs(i);
			}
			if (!flag) break;
		}
		if (flag) {ans = mid,r = mid-1;} else l = mid+1;
	}
	printf("%d\n",a[ans].z);
	return 0;
}
