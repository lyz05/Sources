#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100000+5;
int n,m,ans,a[N],p[N];

bool judge(int len)
{
	memset(p,0,sizeof p);
	int cnt = 0;
	for (int i=1;i<=n;i ++)
	{
		if (a[i]!=0) 
		{
			if (!p[a[i]]) cnt ++;
			p[a[i]] ++; 
		}
		if (a[i-len]!=0 && i-len>0) 
		{
			p[a[i-len]] --;
			if (!p[a[i-len]]) cnt --;
		}
		if (cnt==m) return 1;
	}
	return 0;
}

int main()
{
	freopen("I.in","r",stdin);
	while(~scanf("%d%d",&n,&m))
	{
		for (int i=1;i<=n;i ++) scanf("%d",a + i);
		ans = -1;
		for (int L=m,R=n,mid=(L+R)>>1;L<=R;mid=(L+R)>>1)
		{
			if (judge(mid))
			{
				ans = mid;
				R = mid-1;
			} else L = mid+1;
		}
		printf("%d\n",ans);
	}
}
