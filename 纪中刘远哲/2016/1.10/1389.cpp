#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int M = 25;
int tmp,now,last,ans;
int n,m,T;
int f[M];

int main()
{
	freopen("1389.in","r",stdin);
	//freopen("1389.out","w",stdout);

	
	scanf("%d%d%d\n",&n,&m,&T);
	while (T --)
	{
		memset(f,0,sizeof f);
		for (int i=1;i<=n;i ++)
		{
			char c;
			for (int j=1;j<=m;j ++) 
			{
				scanf("%c",&c);
				if (c=='1') f[j] = f[j]+(1<<(i-1));
			}
			scanf("\n");
		}
		scanf("\n");
		ans = 0;
		for (int i=0;i<(1<<n);i ++)
		{
			now = i;
			last = 0;
			for (int j=1;j<=m;j ++)
			{
				tmp = now;
				now = now^(now<<1)^(now<<2)^(now>>1)^(now>>2)^last^f[j];
				now &= (1<<n)-1;
				last = tmp;
			}
			if (!now) 
				ans ++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
