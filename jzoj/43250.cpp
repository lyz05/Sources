#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20;
int s[N];
int n,ans;

void dfs(int dep,int ret)
{
	if (ret >= ans) return;
	if (dep > 14)
	{
		ans = ret;
		return;
	}
	if (!s[dep]) {
		dfs(dep + 1,ret);
		return;
	}
	if (s[dep] >= 4)
	{
		s[dep] -= 4;
		for (int i = dep + 1;i <= 14;++ i)
			for (int j = i;j <= 14;++ j)
			{
				if (s[i] && s[j] && i != j || s[i] >= 2 && i == j)
				{
					s[i] --,s[j] --;
					dfs(dep,ret + 1);
					s[i] ++,s[j] ++;
				}
				if (s[i] >= 2 && s[j] >= 2 && i != j || s[i] >= 4 && i == j)
				{
					s[i] -= 2,s[j] -= 2;
					dfs(dep,ret + 1);
					s[i] += 2,s[j] += 2;
				}
			}
		dfs(dep,ret + 1);
		s[dep] += 4;
	}
	if (s[dep] >= 3)
	{
		s[dep] -= 3;
		for (int i = dep + 1;i <= 14;++ i)
		{
			if (s[i])
			{
				s[i] --;
				dfs(dep,ret + 1);
				s[i] ++;
			}
			if (s[i] >= 2)
			{
				s[i] -= 2;
				dfs(dep,ret + 1);
				s[i] += 2;
			}
		}
		if (dep > 2)
		{
			int r;
			for (r = dep + 1;r <= 14;++ r) if (s[r] < 3) break;
			for (int i = dep + 1;i < r;++ i)
			{
				s[i] -= 3;
				dfs(dep,ret + 1);
			}
			for (int i = dep + 1;i < r;++ i) s[i] += 3;
		}
		dfs(dep,ret + 1);
		s[dep] += 3;
	}
	if (s[dep] >= 2)
	{
		s[dep] -= 2;
		if (dep > 1)
			for (int i = dep + 1;i <= 14;++ i) if (s[i] >= 3)
			{
				s[i] -= 3;
				dfs(dep,ret + 1);
				if (s[i])
				{
					s[i] --;
					for (int j = dep + 1;j <= 14;++ j) if (s[j] >= 2)
					{
						s[j] -= 2;
						dfs(dep,ret + 1);
						s[j] += 2;
					}
					s[i] ++;
				}
				s[i] += 3;
			}
		if (dep > 2)
		{
			int r;
			for (r = dep + 1;r <= 14;++ r) if (s[r] < 2) break;
			r --;
			if (r - dep > 1)
			{
				s[dep + 1] -= 2;
				for (int i = dep + 2;i <= r;++ i)
				{
					s[i] -= 2;
					dfs(dep,ret + 1);
				}
				for (int i = dep + 1;i <= r;++ i) s[i] += 2;
			}
		}
		dfs(dep,ret + 1);
		s[dep] += 2;
	}
	s[dep] --;
	for (int i = dep + 1;i <= 14;++ i) if (s[i] >= 3)
	{
		s[i] -= 3;
		dfs(dep,ret + 1);
		if (s[i])
		{
			s[i] --;
			for (int j = dep + 1;j <= 14;++ j) if (s[j])
			{
				s[j] --;
				dfs(dep,ret + 1);
				s[j] ++;
			}
			s[i] ++;
		}
		s[i] += 3;
	}
	if (dep > 2)
	{
		int r;
		for (r = dep + 1;r <= 14;++ r) if (!s[r]) break;
		r --;
		if (r - dep > 3)
		{
			for (int i = dep + 1;i <= dep + 3;++ i) s[i] --;
			for (int i = dep + 4;i <= r;++ i)
			{
				s[i] --;
				dfs(dep,ret + 1);
			}
			for (int i = dep + 1;i <= r;++ i) s[i] ++;
		}
	}
	dfs(dep,ret + 1);
	s[dep] ++;
}

int main()
{
	int T;
	scanf("%d%d",&T,&n);
	while (T --)
	{
		memset(s,0,sizeof(s));
		ans = n;
		for (int i = 1;i <= n;++ i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (x == 0) x = 1;
			else if (x == 1) x = 14;
			s[x] ++;
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
}
