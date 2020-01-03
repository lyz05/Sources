#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 5000+5;
struct node
{
	int l,t,id;
} a[N];
LL ans[N];
int n,minT,k;
LL minn;
bool flag;

bool cmp(node A,node B){return A.t<B.t;}
LL sqr(LL x){return x*x;}

void work()
{
	sort(a+1,a+1+n,cmp);
	LL T=0;
	for (int i=1;i<=n;i ++)
	{
		T = (T>a[i].t)?T:a[i].t;
		T += a[i].l;
		ans[a[i].id] = T;
	}
}

int main()
{
	freopen("task.in","r",stdin);
	//freopen("task.out","w",stdout);
	
	scanf("%d",&n);
	flag = 1;
	for (int i=1;i<=n;i ++)
	{
		scanf("%d%d",&a[i].l,&a[i].t);
		a[i].id = i;
		if (i!=1 && a[i].l!=a[i-1].l) flag = 0;
	}
	if (flag)
	{	
		work();
		for (int i=1;i<=n;i ++) printf("%lld ",ans[i]);
		printf("\n");
		return 0;
	}
	//sort(a+1,a+1+n,cmp);
	flag = 1;
	for (LL T=0;flag;)
	{
		minn = 1e9+7;k = 0;minT = 1e9+7;
		flag = 0;
		for (int i=1;i<=n;i ++)
		{
			if (!ans[i])
			{
				minT = min(minT,a[i].t);
				flag = 1;
				if (T>=a[i].t)
				{
					LL tmp = a[i].l-sqr(T-a[i].t);
					if (tmp<minn)
					{
						minn = tmp;
						k = i;
					}
				}
			}
		}
		if (k)
		{
			T += a[k].l;
			ans[k] = T;
		} else T = minT;
	}
	for (int i=1;i<=n;i ++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}

