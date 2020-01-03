#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 1e5+5;
struct node
{
	int y,z,id;
} a[N];

int n,p,tot;
LL ans;

bool cmp(node a,node b)
{
	return (a.y<b.y || (a.y==b.y && a.z>b.z));
}

int main()
{
	freopen("mission.in","r",stdin);
	freopen("mission.out","w",stdout);
	
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i ++)
	{
		int x,y,z;
		scanf("%d%d",&x,&y);
		z = x-y;
		if (i == p) ans = x;
		if (z>=0)
		{
			a[++ tot].y = y;
			a[tot].z = z;
			a[tot].id = i;
		}
	}	
	sort(a+1,a+1+tot,cmp);
	int cnt = -1, flag = 0;
	for (int i=1;i<=tot;i ++)
	{
		if (a[i].id == p)
		{	
			flag = 1;
			continue;
		}
		if (ans>=a[i].y) ans += a[i].z;
		else 
		{
			cnt = i - 1;
			break;
		}
	}
	if (cnt==-1) cnt = tot;
	if (!flag) cnt ++;
	printf("%I64d\n%d\n",ans,cnt);
	return 0;
}
