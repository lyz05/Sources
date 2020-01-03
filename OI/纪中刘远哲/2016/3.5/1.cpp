#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100000+5;
int x[N],y[N],s[N];
int n,m,T;
long long ans;

void work()
{
	int t;
	if (T%n==0)
	{
		s[0] = 0;
		for (int i=1;i<=n;i ++) s[i] = s[i-1]+x[i];
		sort(s+1,s+1+n);
		t = s[(n+1)>>1];
		for (int i=1;i<=n;i ++) ans += abs(t - s[i]);
	}
	if (T%m==0)
	{
		s[0] = 0;
		for (int i=1;i<=m;i ++) s[i] = s[i-1]+y[i];
		sort(s+1,s+1+m);
		t = s[(m+1)>>1];
		for (int i=1;i<=m;i ++) ans += abs(t - s[i]);
	}

}

int main()
{
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);

	scanf("%d%d%d",&n,&m,&T);
	for (int i=1;i<=T;i ++) 
	{
		int a,b;
		scanf("%d%d",&a,&b);
		x[a] ++,y[b] ++;
	}
	if (T%n&&T%m) 
	{
		puts("impossible");
		return 0;
	}
	for (int i=1;i<=n;i ++) x[i] -= T/n;
	for (int i=1;i<=m;i ++) y[i] -= T/m;
	work();
	if (T%n==0&&T%m==0) printf("both");
	else if (T%n==0) printf("row");
	else printf("column");
	printf(" %lld\n",ans);	

	return 0;
}
