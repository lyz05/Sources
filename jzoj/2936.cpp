#include <cstdio>
#include <algorithm>
using namespace std;

void add(int x,int y,int z)
{
	tot ++;
	h[tot].y = y;
	h[tot].w = z;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int x)
{
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y, w = h[i].w;
		int z = dfs(y);
		if (p[x]) 
		{
			if (p[y]) ans += w;
			else ans += min(w,z);
		} else 
		{

			//if (tmp<w) ans += tmp , tmp = w;
		}
	}
}

int main()
{
	freopen("2936.in","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i ++) 
	{
		int tmp;
		scanf("%d",tmp);
		p[tmp] = true;
	}
	for (int i=1;i<n;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,z);
	}
	dfs(0);
	return 0;
}
