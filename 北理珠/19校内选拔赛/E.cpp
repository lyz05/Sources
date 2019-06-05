#include <cstdio>
using namespace std;

const int N = 100000+5,INF=1e9+7;
int a[N],n,ans;

bool judge(int level)
{
	for (int i=1;i<=n;i ++)
	{
		level = level + (level-a[i]);
		if (level<=0) return 0;
		if (level>INF) return 1;
	}
	return 1;
}

int main()
{
	while (~scanf("%d",&n))
	{
		for (int i=1;i<=n;i ++) scanf("%d",a + i);
		for (int L=1,R=INF,mid=(L+R)>>1;L<=R;mid=(L+R)>>1)
		{
			if (judge(mid))
			{
				ans = mid;
				R = mid-1;
			} else L = mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
