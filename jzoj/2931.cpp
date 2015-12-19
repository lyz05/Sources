#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;

const LL INF = 1LL<<60LL;
const int N = 100000+5;
LL tot = 0,L,beg;
int n,q[2*N+500];
LL h[N],w[N],f[N];
multiset <LL> tree;
int main()
{
	freopen("2931.in","r",stdin);
	int l=0,r=-1,pos=1;
	tree.clear(); tree.insert(INF);
	scanf("%d%lld",&n,&L);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld",h + i,w + i);
		tot += w[i];
		while (tot>L) tot -= w[pos++];
		while (l<=r && h[i]>=h[q[r]])
		{
			if (l<r)
			{
				tree.erase(f[q[r-1]]+h[q[r]]);	
			}
			r --;
		}
		q[++ r] = i;
		if (l<r)
			tree.insert(f[q[r-1]]+h[q[r]]);
		while (q[l]<pos)
		{
			if (l<r) tree.erase(f[q[l]]+h[q[l+1]]);
			l ++;
		}
		f[i] = f[pos-1]+h[q[l]];
		beg = *tree.begin();
		if (f[i]>beg) f[i] = beg;
	}
	printf("%lld\n",f[n]);
	return 0;

}
