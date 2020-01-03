#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1000000+7;
int n,T;
int a[N],f[N];
map <int,int> p;

int main()
{
	freopen("C.in","r",stdin);
	while (1)
	{
		scanf("%d%d",&n,&T);
		if (n == 0 && T == 0) break;
		for (int i = 1;i <= n;i ++) 
			scanf("%d",a + i);
		memset(f,0,sizeof f);
		p.clear();
		f[n] = n+1;
		p[a[n]] = n;
		for (int i=n-1;i>=1;i --)
		{
			if (p[a[i]]==0)
			{
				f[i] = f[i+1];
			}else
				f[i] = min(f[i+1],p[a[i]]);
			p[a[i]] = i;
		} 
		while (T --)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (f[x]>y) printf("OK\n");else printf("%d\n",a[f[x]]);
		}
		//scanf("\n");
	}
	return 0;
 } 
