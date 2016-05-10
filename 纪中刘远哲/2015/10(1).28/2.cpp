#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

typedef long long LL;
const int N = 100000;
int n;
LL tmp,ans;
struct node
{
	int val,id;
} a[N];
int b[N],c[N];
bool vis[N];
map <int,int>p;

void dfs(int dep)
{
	if (dep>n) 
	{
		if (tmp>ans)
		{
			ans = tmp;
			memcpy(c,b,sizeof b);
		}
		return;
	}
	for (int i=1;i<=n;i ++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			b[dep] = i;
			tmp += a[b[dep]].val*a[b[dep-1]].val;
				dfs(dep+1);
			tmp -= a[b[dep]].val*a[b[dep-1]].val;
			b[dep] = 0;
			vis[i] = 0;
		}
	}
}

bool cmp(node A,node B) {return A.val<B.val;}

void work()
{
	sort(a+1,a+1+n,cmp);
	b[0] = 0;
	for (int i=1;i<=n;i += 2) b[++ b[0]] = i;
	for (int i=(n%2==0)?n:n-1;i>=1;i-=2) b[++ b[0]] = i;
	for (int i=1;i<=n;i ++) c[i] = a[b[i]].id;
	bool flag = 0;
	for (int i=1;i<=n/2;i ++)
		if (c[i]<c[n-i+1]) {flag = 0;break;}
		else if (c[i]>c[n-i+1]) {flag = 1;break;}
	if (flag) 
		for (int i=n;i>=1;i --) c[n-i+1] = a[b[i]].id;
}

int main()
{
	freopen("permutation.in","r",stdin);
	//freopen("permutation.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		bool flag = 1;
		p.clear();
		scanf("%d",&n);
		for (int i=1;i<=n;i ++) 
		{
			scanf("%d",&a[i].val);
			a[i].id = i;
			if (p.count(a[i].val)==0) p[a[i].val] = 1;
			else flag = 0;
		}
		tmp = 0;ans = -1;
		memset(b,0,sizeof b);
		if (flag) work(); else dfs(1);
		for (int i=1;i<=n;i ++) printf("%d ",c[i]);
		puts("");
	}

	return 0;
}

