#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

typedef long long LL;
const int N = 300000+100;
map<int,int> h[N];
char s[10];
int t,tot,n,m;
LL p,ans;

int main()
{
	freopen("grimoire.in","r",stdin);
	//freopen("grimoire.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		scanf("%s%d%lld",s,&t,&p);
		if (s[0]=='B') {
			if (tot+1<=n) 
			{
				if (h[t][0]+1<=t)
				{
					h[t][0] ++;
					h[t][p] ++;
					tot ++;
					ans += p;
				}
			}
		}else 
		{
			if (tot-1>=0) 
			{
				if (h[t][p]-1>=0)
				{
					h[t][0] --;
					h[t][p] --;
					tot --;
					ans -= p;
				}
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
