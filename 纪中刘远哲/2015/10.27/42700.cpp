#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 300000+100;
struct node {int size,num,p;} h[N]; 
char s[10];
int t,tot,n,m;
LL p,ans;

void ha(int kind,int t,LL p)
{
	int x = p % N;
	for (;;x=(x+1)%N)
	{
		if (!h[x].size && !h[x].p)
		{
			if (kind)
			{
				h[x].size = t;
				h[x].p = p;
			}else return;
		}
		if (h[x].size==t && h[x].p==p)
		{
			if (kind)
			{
				if (h[x].num+1<=h[x].size)
				{
					h[x].num ++;
					ans += p;
					tot ++;
				}
			} else 
			{
				if (h[x].num-1>=0)
				{
					h[x].num --;
					ans -= p;
					tot --;
				}
			}
			return;
		}
	}
}

int main()
{
	//freopen("grimoire.in","r",stdin);
	//freopen("grimoire.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		scanf("%s%d%lld",s,&t,&p);
		if (s[0]=='B') {
			if (tot+1<=n) ha(1,t,p);
		}else 
		{
			if (tot-1>=0) ha(0,t,p);
		}
		printf("%lld\n",ans);
	}

	return 0;
}
