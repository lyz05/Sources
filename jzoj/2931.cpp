#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100000+5;
int n,l,w[N],h[N],f[N];
int main()
{
	freopen("2931.in","r",stdin);
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d%d",h + i,w + i);
		w[i] += w[i-1];
	}

	memset(f,125,sizeof f);
	f[0] = 0;
	for (int i=1;i<=n;i++)
	{
		int maxx = h[i];
		for (int j=i-1;j>=0;j--)
		{
			if (w[i]-w[j]>l) break;
			f[i] = min(f[i],f[j]+maxx);
			maxx = max(maxx,h[j]);
		}
	}
	printf("%d\n",f[n]);

	return 0;
}

