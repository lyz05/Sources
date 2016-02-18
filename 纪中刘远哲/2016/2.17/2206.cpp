#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <list>
using namespace std;

typedef long long LL;
const int N = 400005;
list <int> Q;
int L[N],R[N],h[N];
int n;
LL ans;

void calcL()
{
	Q.clear();
	Q.push_back(0);
	for (int i=1;i<=n;i ++)
	{
		while (!Q.empty() && h[Q.back()]>=h[i]) Q.pop_back();
		L[i] = i - Q.back() - 1;
		Q.push_back(i);
	}
}

void calcR()
{
	Q.clear();
	Q.push_back(n+1);
	for (int i=n;i>=1;i --)
	{
		while (!Q.empty() && h[Q.back()]>=h[i]) Q.pop_back();
		R[i] = Q.back() - i - 1;
		Q.push_back(i);
	}
}

void get()
{
	for (int i=1;i<=n;i ++)
	{
		LL tmp = (LL)h[i]*(R[i]+L[i]+1);
		ans = max(ans,tmp);
	}
}

int main()
{
	//freopen("2206.in","r",stdin);
	//freopen("2206.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",h + i);
	calcL();calcR();get();
	printf("%lld\n",ans);
	return 0;
}
