#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 205;
const LL mo = 1e17;
int n,m,ans;
int s[N],c[N],a[N][4];

void dfs(int x,int y)
{
	if (y>m) x ++, y = 1;
	if (x>n)
	{
		ans ++;
		return;
	}
	for (int i=0;i<=100;i ++)
	{
		if ((y==m && i!=s[x]) || (x==n && i!=c[y])) continue; 
		a[x][y] = i;
		s[x] -= i,c[y] -= i;
		if (s[x]>=0 && c[y]>=0)
			dfs(x,y+1);
		s[x] += i,c[y] += i;
		a[x][y] = 0;
	}
}

int main()
{
	freopen("data.in","r",stdin);
	//freopen("1.out","w",stdout);

	m = 3;
	scanf("%d",&n);
	for (int i=1;i<=m;i ++) scanf("%d",c + i);
	for (int i=1;i<=n;i ++) scanf("%d",s + i);

	dfs(1,1);
	printf("%d\n",ans);

	return 0;
}

