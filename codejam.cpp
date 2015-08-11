#include <cstdio>

using namespace std;

const int N=1000;

int sm,n,cnt,ans;
char s[N];

int main()
{
	freopen("codejam.in","r",stdin);
	int t;
	scanf("%d",&t);
	while (t--)
	{
		cnt = 0;ans = 0;
		scanf("%d %s",&n,&s);
		for (int i=0;i<n;i ++)
		{
			cnt += (s[i]-'0');
			while (cnt<i) 
			{
				ans ++;
				cnt ++;
			}
		}
		printf("Case #1: %d\n",ans);
	}
	return 0;
}
