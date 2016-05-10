#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 50000+5;
struct node
{int num,id;} b[N];
int n,m,l,ans;
int a[N];

bool cmp(node A,node B)
{return (A.num<B.num || (A.num==B.num && A.id<B.id));}

int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);

	scanf("%d%d%d",&l,&n,&m);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	
	a[n+1] = l;
	for (int i=1;i<=n+1;i ++)
	{
		b[i].num = a[i]-a[i-1];
		b[i].id = i;
	}
	sort(b + 1,b + 1 + n,cmp);
	for (int i=1;i<=m;i ++) 
	{
		a[b[i].id] = a[b[i].id-1]; 
	}
	ans = 1e9+7;
	for (int i=1;i<=n+1;i ++)
		if (a[i]-a[i-1]<ans && a[i]-a[i-1]!=0)
			ans = a[i]-a[i-1];
	printf("%d\n",ans);
	return 0;
}

