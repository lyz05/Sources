#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 1000005,oo=1e9;
int n,k,c,head,tail,a[N],q[N];
LL f[N];

LL sqr(LL x){return x*x;}
LL s(int k ,int j){return (a[k+1]-a[j+1]);} 
LL g(int k ,int j){return (f[k]-f[j]+sqr(a[k+1])-sqr(a[j+1]));}

void add(int i)
{
	while (head<tail && a[q[tail]]==a[i]) tail --;
	while (head<tail && g(q[tail],i)*s(q[tail-1],q[tail])<s(q[tail],i)*g(q[tail-1],q[tail])) tail --;
	while (head<tail && a[q[tail]]==a[i]) tail --;
	q[++ tail] = i;
}

int main()
{
	freopen("3479.in","r",stdin);

	scanf("%d%d%d",&n,&k,&c);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + 1 + n);
	memset(f,255,sizeof f);
	memset(q,0,sizeof q);
	f[0]=0;
	head=1;tail=0;
	a[0]=oo;a[n+1]=oo;
	for (int i=k; i <= n ; i ++)
	{
		if (f[i-k]!=-1) add(i-k);
		while (head<tail && (a[q[head]]==a[q[head+1]] || g(q[head],q[head+1])>2*a[i]*s(q[head],q[head+1]))) head ++;
		if (head <= tail) f[i] = f[q[head]] + sqr(a[i]-a[q[head]+1]) + c;
	}
	printf("%lld\n",f[n]);
	return 0;
}
