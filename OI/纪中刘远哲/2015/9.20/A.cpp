#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int M = 1e5+5 , N = 20000+5 , Maxq = 5000+5;
struct node1
{
	int x,y,d;
} e[M];
struct node2
{
	int d,id;
} Q[Maxq];

int n,m,q;
int h[N],size[N];
LL last,ans[Maxq];

bool cmp1(node1 A,node1 B)
{return A.d<B.d;}
bool cmp2(node2 A,node2 B)
{return A.d<B.d;}


void prepar()
{
	for (int i=1;i<=n;i ++) h[i] = i , size[i] = 1;
}

int gf(int x)
{
	if (x == h[x])
		return x;
	else {
		h[x] = gf(h[x]);
		return h[x];
	}
}

void link(int x,int y)
{
	int i = gf(x) , j = gf(y);
	if (i == j)
	{
		return;
	} else 
	{
		LL ret1 = size[i]*(size[i]-1), ret2 = size[j]*(size[j]-1);
		last -= ret1;
		last -= ret2;
		h[i] = j;
		size[j] += size[i];
		size[i] = 0;
		last += size[j] * (size[j]-1);
	}
}

int main()
{
	freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		scanf("%d%d%d",&n,&m,&q);
		for (int i=1;i<=m;i ++)
		{
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].d);
		}
		for (int i=1;i<=q;i ++)
		{
			scanf("%d",&Q[i].d);
			Q[i].id = i;
		}
		sort(e + 1,e + 1 + m,cmp1);
		sort(Q + 1,Q + 1 + q,cmp2);
		prepar();
		
		int j = 0;
		last = 0;
		for (int i=1;i<=q;i ++)
		{
			while (e[j+1].d <= Q[i].d && j+1<=m)
			{
				j ++;
				link(e[j].x,e[j].y);
			}
			ans[Q[i].id] = last;
		}
		for (int i=1;i<=q;i ++)
			printf("%I64d\n",ans[i]);
	}

	return 0;
}

