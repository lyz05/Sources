#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=25;
int n,a[N],f[N],g[N];

int main()
{
	freopen("1303.in","r",stdin);
	int x;
	while (scanf("%d,",&x)!=EOF) a[++n]=x;
	
	for (int i=1;i<=n;i++) f[i]=1,g[i]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
		{
			if (a[j]>=a[i]) f[i]=max(f[i],f[j]+1);
			if (a[j]<a[i]) g[i]=max(g[i],g[j]+1);
		}
	for (int i=1;i<=n;i++)
	{
		f[0]=max(f[0],f[i]);
		g[0]=max(g[0],g[i]);
	}
	printf("%d,%d\n",f[0],g[0]-1);
	
	return 0;
}

