#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 105;
int h[N];

int gf(int x)
{
	if (x==h[x]) return x;
	else return h[x] = gf(h[x]);
}

bool link(int x,int y)
{
	int i = gf(x),j = gf(y);
	if (i==j) return 0;
	else 
	{
		h[i] = j;
		return 1;
	}
}

int main()
{
	int Case,S,T,n,m;
	scanf("%d",&Case);
	while (Case --)
	{
		scanf("%d%d%d%d",&n,&m,&S,&T);
		for (int i=1;i<=n;i ++) h[i] = i;
		for (int i=1;i<=m;i ++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			link(x,y);
		}
		if (!link(S,T)) printf("Yes\n"); else printf("No\n"); 
	}
} 
