#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100001;
int h[N+7],a[N],n;

int lowbit(int x) { return x&(-x);} 

int query(int x)
{
	int cnt = 0;
	while (x>0)
	{
		cnt += h[x];
		x -= lowbit(x);
	}
	return cnt;
}
void add(int x)
{
	while (x<=N)
	{
		h[x] ++;
		x += lowbit(x);
	}
}

int main()
{
	freopen("D.in","r",stdin);
	while (~scanf("%d",&n))
	{
		memset(h,0,sizeof h);
		int ans = 0;
		for (int i=1;i<=n;i ++) scanf("%d",a+i);

		for (int i=n;i>=1;i --)
		{
			ans += query(a[i]-1);
			add(a[i]);
			//printf("%d %d\n",a[i],ans);
		}
		printf("%d\n",ans);
	}
	return 0;
} 
/*
		for (int i=n;i>=1;i --)
		{
			ans += query(a[i]);
			add(a[i]);
			//printf("%d %d\n",a[i],ans);
		}
		for(int i=1;i<=n;++i){
        	ans+=query(N-7)-query(a[i]);
        	add(a[i]);
    	}
//10101010
*/
