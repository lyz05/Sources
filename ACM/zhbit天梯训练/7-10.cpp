#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 105;
bool map[N][N]={};
int h[N],n,m,k;

int gf(int x)
{
	if (x==h[x]) return x;
	else return h[x] = gf(h[x]);
}

bool link(int x,int y)
{
	int i=gf(x),j=gf(y);
	if (i==j) return 0;
	else 
	{
		h[i] = j;
		return 1;
	}
}

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i ++) h[i] = i; 
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (z==1) link(x,y); else map[x][y] = map[y][x] = 1;
	}
	for (int i=1;i<=k;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		bool flag1 = gf(x)==gf(y),flag2 = map[x][y];
		if (flag1&&(!flag2)) puts("No problem");
		if ((!flag1)&&(!flag2)) puts("OK");
		if (flag1&&flag2) puts("OK but...");
		if ((!flag1)&&(flag2)) puts("No way");
	}
	return 0;
}
