#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long LL;

const int N = 2000;
LL n,m,p[N],a[N],ans;
bool fflag;

LL calc()
{
	LL ret = 1;
	for (int i=1;i<=m;i ++)
		if (a[i]) ret *= p[i];
	return ret;
}

void dfs(int dep,int flag)
{
	if (dep>m)
	{
		if (fflag) 
			ans = ans + (flag?1:-1)*n/calc();
		fflag = 1;
		return;
	}
	for (int i=0;i<2;i ++)
	{
		a[dep] = i;
		dfs(dep+1,flag^i);
	}
}

int main()
{
	cin >> n >> m;
	for (int i=1;i<=m;i ++) cin >> p[i];
	dfs(1,0);
	cout << ans << endl;
	return 0;
} 
