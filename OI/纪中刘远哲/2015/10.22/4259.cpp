#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long LL;
const int N = 4000+10;
int a,n,b[N],hash[N*9];
char s[N];
LL ans;

int main()
{
	freopen("4259.in","r",stdin);
	scanf("%d",&a);
	scanf("%s",s);
	n = strlen(s);
	for (int i=0;i<n;i ++) b[i+1] = s[i]-'0';
	for (int i=1;i<=n;i ++)
	{
		int tmp = 0;
		for (int j=i;j<=n;j ++)
		{
			tmp += b[j];
			hash[tmp] ++;
		}
	}
	for (int i=1;i<=floor(sqrt(a));i++)
	{
		if (a%i==0)
		{
			int j = a / i;
			if (i>4000*9 || j>4000*9) continue;
			ans += 2*(hash[i]*hash[j]);
		}
	}
	if (a==0)
	{
		for (int i=0;i<=4000*9;i ++)
			ans += 2*(hash[0]*hash[i]);
		ans = ans-hash[0]*hash[0];
	}
	printf("%lld\n",ans);
}
