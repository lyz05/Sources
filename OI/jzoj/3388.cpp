#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 100000+5;
struct node
{int y,next,len;} h[2*N];
int n,m,tot;
int e[N],d[N],dd[N];
double f[N];

void add(int x,int y,int z)
{
	h[++ tot].y = y;
	h[tot].len = z;
	h[tot].next = e[x];
	d[y] ++;
	dd[y] ++;
	e[x] = tot;
}

void work(int x)
{
	static queue <int> Q;
	Q.push(x);
	while (!Q.empty())
	{
		int y = Q.front();Q.pop();
		for (int i=e[y];i;i=h[i].next)
		{
			int x = h[i].y;
			f[x] += (f[y]+h[i].len)/d[x];
			dd[x] --;
			if (!dd[x]) Q.push(x);
		}
	}
}

int main()
{
	freopen("3388.in","r",stdin);
	//freopen("3388.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(y,x,z);
	}
	work(n);
	printf("%.2f\n",f[1]);

	return 0;
}
