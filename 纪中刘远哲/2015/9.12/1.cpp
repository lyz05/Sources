#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 3000+5;
int d[N],r[N],ans[N];
int n,tot,cnt;

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("mission.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
		scanf("%d%d",&d[i],&r[i]);
	tot = n; cnt = 0;
	while (tot)
	{
		cnt ++;
		for (int i=1;i<=n;i++)
		{				// A
			if (ans[i] && ans[i]!=cnt) continue;
			bool flag = 1;
			for (int j=1;j<=n;j ++)
			{
				if (ans[j] && ans[j]!=cnt) continue;
				if (d[j]>d[i] && r[j]>r[i])
				{
					flag = 0;	
					break;
				}
			}
			if (flag) 
			{ 
				tot --;
				ans[i] = cnt;
			}
			if (!tot) break;
		}
	}
	for (int i=1;i<=n;i ++) printf("%d\n",ans[i]);
	return 0;
}
