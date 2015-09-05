#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20000+5;
struct node
{
	int x,y,z;
} a[N];
struct node1
{
	int y,next;
} h[2*N];
int T,tot,ans,n;
int e[N],f[N];

bool cmp(node x,node y) {return x.z<y.z;}

void add(int x,int y)
{
	tot ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

bool judge(int x,int y)
{
	for (int i = e[x];i;i = h[i].next)
	{
		if (h[i].y==y) return 1;
	}
	return 0;
}

int gf(int x)
{
	if (x == f[x]) return x; else 
	{
		f[x] = gf(f[x]);
		return f[x];
	}
}

bool link(int x,int y,bool p)
{
	int i=gf(x),j=gf(y);
	if (i!=j) 
	{
		if (p) f[i] = j;
		return 1;
	} else return 0;
}

void work(int sum)
{
	for (int i=1;i<=n;i ++)
		for (int j=i+1;j<=n;j ++)
			if (!link(i,j,0) && !judge(i,j)) 
			{
				add(i,j);add(j,i);
				ans += sum;
			}
}

int main()
{
	freopen("2940.in","r",stdin);
	
	scanf("%d",&T);
	while (T --)
	{
		memset(h,0,sizeof h);
		memset(e,0,sizeof e);
		ans = 0;tot = 0;
		scanf("%d",&n);
		for (int i=1;i<=n;i ++) f[i] = i;
		for (int i=1;i<n;i ++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			a[i].x = x, a[i].y = y, a[i].z = z;
		}
		sort(a + 1,a + n,cmp);
		a[n].z = a[n-1].z+1;
		for (int i=1;i<n;i++)
		{
			ans += a[i].z;
			link(a[i].x,a[i].y,1);
			add(a[i].x,a[i].y);add(a[i].y,a[i].x);
			if (a[i].z<a[i+1].z) work(a[i].z+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
