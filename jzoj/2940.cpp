#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20000+5;
struct node
{
	int x,y,z;
} a[N];

int T,tot,n;
long long f[N],size[N];
long long ans;

bool cmp(node x,node y) {return x.z<y.z;}

int gf(int x)
{
	if (x == f[x]) return x; else 
	{
		f[x] = gf(f[x]);
		return f[x];
	}
}

void link(int x,int y,int z)
{
	int i=gf(x),j=gf(y);
	if (i!=j) 
	{
		ans += (size[i]*size[j]-1)*(z+1);
		size[j] += size[i];
		f[i] = j;
	}
}


int main()
{
	freopen("2940.in","r",stdin);
	
	scanf("%d",&T);
	while (T --)
	{
		ans = 0;tot = 0;
		scanf("%d",&n);
		for (int i=1;i<=n;i ++) f[i] = i , size[i] = 1;
		for (int i=1;i<n;i ++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			a[i].x = x, a[i].y = y, a[i].z = z;
		}
		sort(a + 1,a + n,cmp);
		//a[n].z = a[n-1].z+1;
		for (int i=1;i<n;i++)
		{
			ans += a[i].z;
			link(a[i].x,a[i].y,a[i].z);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
