#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL maxans = 1e15;
const int N=15+5;
int n,k,a[N],tot;

struct node
{
	int num;
	LL val;

}inf[1<<15+5];

int gcd(int x,int y)
{
	if (y==0) return x;else return gcd(y,x % y);
}

void make(int dep,int st,LL now)
{
	if (dep!=0) inf[++tot].num=dep , inf[tot].val=now;
	for (int i = st+1;i <= n;i ++)
	{
		LL j;
		j = (a[i]*now)/gcd(now,a[i]);
		if (j>maxans) continue;
		make(dep+1,i,j);
	}
}

LL P(LL x)
{
	LL sum = 0;
	for (int i=1;i<=tot;i++)
	{
		if (inf[i].num % 2) sum += x/inf[i].val * inf[i].num;
		else sum -= x/inf[i].val*inf[i].num;
	}
	return sum;
}

int main()
{
	freopen("1241.in","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	make(0,0,1);

	LL l = 1 ,r = maxans,mid,p;
	while (l<=r)
	{
		mid = (l+r)>>1;
		p = P(mid);
		if (p<k) l = mid+1; else r = mid-1;
	}
	
	printf("%lld\n",l);
	return 0;
}
