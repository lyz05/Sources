#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=100000+5;
const int M=N;
int n,m,a[N],b[M],ans;
bool pa[N],pb[M];

int work()
{
	int i=1,j=1;
	while ((i<=n) && (j<=m))
	{
		while ((j<m)&&(abs(a[i]-b[j])>abs(a[i]-b[j+1]))) j++;
		ans+=abs(a[i]-b[j]);
		pb[j]=true;
		i ++;
	}
	i=1;j=1;
	while ((i<=n) && (j<=m))
	{
		while (pb[j]) j++;
		if (j>m) break;
		while ((i<n)&&(abs(a[i]-b[j])>abs(a[i+1]-b[j]))) i++;
		ans += abs(a[i] - b[j]);
		pb[j]=true;
		j ++;
	}
}

int main()
{
	freopen("4.in","r",stdin);
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int j=1;j<=m;j++) scanf("%d",&b[j]);
		sort(a + 1,a + n + 1);sort(b + 1,b + n + 1);
		memset(pa,0,sizeof pa);memset(pb,0,sizeof pb);
		ans = 0;
		work();
		printf("%d\n",ans);	
	}
	return 0;
}
