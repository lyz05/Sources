#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 100000+5;
LL n,l,c;
LL ans;
LL a[N],maxx;

struct node
{
	LL x,y;
} b[N];

LL tmp[N]; 

bool cmp(node a,node b)
{
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

void merge(int l,int m,int r)
{
	int i = l,j = m + 1, k = l;
	while (i <= m && j <= r)
	{
		if (b[i].y > b[j].y)
		{
			tmp[k ++] = b[j ++].y;
			ans -= m-i+1;
		}
		else 
		{
			tmp[k ++] = b[i ++].y;
		}
	}
	while (i <= m) tmp[k++] = b[i++].y;
	while (j <= r) tmp[k++] = b[j++].y;
	for (int i=l;i<=r;i++)
		b[i].y = tmp[i];
}

void merge_sort(int l,int r)
{
	if (l < r)
	{
		int m = (l+r) >> 1;
		merge_sort(l,m);
		merge_sort(m+1,r);
		merge(l,m,r);
	}
}

int main()
{
	freopen("2930.in","r",stdin);
	scanf("%lld%lld%lld",&n,&l,&c);
	for (int i=1;i<=n;i ++) 
		scanf("%lld",&a[i]) , maxx = max(maxx,a[i]);
	for (int i=1;i<=n;i ++)	
		a[i] *= l;
	c = maxx;

	for (int i=1;i<=n;i ++) b[i].x = a[i]/c , b[i].y = a[i]%c;
	sort(b+1,b+1+n,cmp);
	
	ans = 0;
	for (int i=1;i<=n;i ++) ans += b[i].x*(i-1-n+i);
	merge_sort(1,n);

	printf("%lld\n",ans);
	return 0;
}

