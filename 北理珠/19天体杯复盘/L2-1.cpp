#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+7;
int A,B;
int a[N],vis[N],p[N];

bool prime(int x)
{
	for (int i=2;i<=floor(sqrt(x));i ++)
	{
		if (x%i==0) return 0;
	}
	return 1;
}

int calc(int x)
{
	int ret = 0;
	while (x)
	{
		int t = x%10;
		ret += t*t;
		x/=10;
	}
	return ret;
}

int dfs(int x)
{
	if (a[x]) return a[x];
	int next = calc(x);
	if (!vis[next])
	{ 
		vis[next] = 1;
		if (dfs(next) == -1) return a[x] = -1;
		p[next] = 1;
		a[x] = dfs(next)+1;
		vis[next] = 0;
	} else a[x] = -1;
	return a[x];
}

int main()
{
	a[1] = 1;
	scanf("%d%d",&A,&B);
	for (int i=A;i<=B;i ++)
		a[i] = dfs(i);
	bool flag = 0;
	for (int i=A;i<=B;i ++)
		if (a[i]>0 && !p[i]) flag = 1,printf("%d %d\n",i,(a[i]-1)*(1+prime(i)));
	if (!flag) printf("SAD\n");
} 
