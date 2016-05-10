#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5+5;
char s[10];
int l,r,v,n,m;
int a[N];

bool judge(int x)
{
	for (;x;x /= 10) 
		if (x % 10 != 4 && x % 10 != 7) 
			return 0;
	return 1;
}

int main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++)
		scanf("%d",a + i);
	while (m --)
	{
		scanf("%s%d%d",s,&l,&r);
		if (s[0]=='a')
		{
			scanf("%d",&v);
			for (int i=l;i<=r;i ++)
				a[i] += v;
		} else
		{
			int ans = 0;
			for (int i=l;i<=r;i ++)
				if (judge(a[i])) ans ++;
			printf("%d\n",ans);	
		}
	}

	return 0;
}
