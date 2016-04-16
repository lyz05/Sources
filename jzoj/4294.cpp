#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 200000+5;
char s[N];
int x[N],y[N],z[N],ans[N];
int n,k,m;

int main()
{
	freopen("copypaste.in","r",stdin);
	//freopen("copypaste.out","w",stdout);

	scanf("%d%d",&k,&m);
	scanf("%s",s);
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d%d%d",x+i,y+i,z+i);

	for (int num=0;num<k;num ++)
	{
		int now = num;
		for (int i=n;i>0;i --)
		{
			if (z[i]<=now)
			{
				if (now-z[i]+x[i]<y[i])
					now = now-z[i]+x[i];
				else	now -= y[i]-x[i];
			}
		}
		ans[num] = now;
	}
	for (int i=0;i<k;i ++) printf("%c",s[ans[i]]);
	return 0;
}
