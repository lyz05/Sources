#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 50000+5,INF = 1e9+7;
struct node
{int num,id;} b[N];
int n,m,l,ans,tmp,k,kk;
int a[N];

bool cmp(node A,node B)
{return (A.num<B.num || (A.num==B.num && A.id<B.id));}

int main()
{
	freopen("stone.in","r",stdin);
	//freopen("stone.out","w",stdout);

	scanf("%d%d%d",&l,&n,&m);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	a[n+1] = l;
	
	for (int j=1;j<=m+1;j ++)
	{
		for (int i=1;i<=n+1;i ++)
		{
			b[i].num = a[i]-a[i-1];
			if (b[i].num==0) b[i].num = INF;
			b[i].id = i;
		}
		sort(b + 1,b + 1 + n,cmp);
		if (j==m+1) break;
		ans = 1e9+7;
		for (int i=1;i<n;i ++)
		{
			if (a[i]==a[i-1]) continue;
			int id = b[i].id;
			if (id==1) tmp = a[2]-a[0],k = 1;
			else if (id==n+1) tmp = a[n+1]-a[n-1],k=n;
			else 
			{
				if (a[id+1]-a[id-1]<a[id]-a[id-2])
					tmp = a[id+1]-a[id-1],k=id;
				else	tmp = a[id]-a[id-2],k=id-1;
			}
			if (tmp<ans) ans = tmp,kk = k;
			if (b[i].num!=b[i+1].num) break;
		}
		a[kk] = a[kk-1];
	}
	printf("%d\n",b[1].num);
	return 0;
}


