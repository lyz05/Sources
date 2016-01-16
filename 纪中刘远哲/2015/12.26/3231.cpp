#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

const int N = 100005,M = 2097151+5;
int n,m,T,ans;
int a[N],map[M];
char s[10];

int get(char s[])
{
	int len = strlen(s+1),ret = 0;
	for (int i=1;i<=len;i ++)
	{
		if (isdigit(s[i])) ret = ret*16+s[i]-'0';
		else ret = ret*16+s[i]-'A'+10;
	}
	return ret;
}

bool dfs(int st,int last,int used,int ans)
{
	if (used>ans)
	{
		for (int i=1;i<=n;i ++) 
			if (map[a[i]^st]==T) 
				return 1;
		return 0;
	}
	for (int i=last+1,bin=1<<i;i<=20;i ++,bin = (1<<i))
	{
		if (dfs(st+bin,i,used+1,ans)) return 1;
	}
	return 0;
}

int main()
{
	freopen("3231.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&T);
	for (;T;T --)
	{
		scanf("%d",&n);
		bool flag = 0;
		for (int i=1;i<=n;i ++)
		{
			scanf("%s",s+1);
			if (flag) continue;
			a[i] = get(s);
			if (map[a[i]] == T) flag = 1;
			map[a[i]] = T;
		}
		ans = 1;
		if (flag) printf("0\n");
		else
		{
			while (1)
			{
				if (dfs(0,-1,1,ans)) break;
				ans ++;
			}
			printf("%d\n",ans);
		}
	}

	return 0;
}
