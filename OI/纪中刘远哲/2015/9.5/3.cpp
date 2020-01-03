#include <cstdio>
#include <algorithm>

typedef long long LL;
int n;
LL m;
char s[N][M];

int main()
{
	s[1]="a";s[2]="b";
	int T;
	scanf("%d",&T);
	while (T --)
	{
		scanf("%d%lld",&n,&m);
		for (int i=1;strlen(s[i-1])<m;i ++)
		{
			if (strlen(s[i])=0)
				s[i] = s[i-1]+s[i-2];
		}
	}
	return 0;
}
