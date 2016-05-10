#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 60;
struct node
{
	int y,next,w;
} h[N][N];

typedef int one [N];

int ans[N],size[N];
one e[N]
int n;

void combine(int z,int x,int y,int idx,int idy)
{
	//idy += size[x];
	memcpy(h[z],h[x],sizeof x);
	memcpy(e[z],e[x],sizeof x);
	for (int i=1;i<=size[y])
	{
		add()
	}  
}

int main()
{
	size[1]=1;
	int T;
	scanf("%d",&T);
	while (T --)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			int a,b,c,d,l;
			scanf("%d%d%d%d%d",&a,&b,&c,&d,&l);
			int t1=dfs(h[a],c);
			int t2=dfs(h[b],d);
			ans[i]=ans[a]+ans[b]+
				size[a]*size[b]*l+
				size[a]*m+size[b]*n;
			combine(i,a,b,c,d);
		}
		for (int i=1;i<=n;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
