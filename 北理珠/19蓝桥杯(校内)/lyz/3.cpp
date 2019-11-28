#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int ans,n = 2019;

void dfs(int dep,int cnt)
{
	if (cnt==0)
	{
		ans ++;
		//if (ans %10000000 == 0)
		//	cout << ans << endl;
		return;
	}
	if (dep>n) return;
	
	for (int i=0;i<=1;i ++)
	{
		dfs(dep+1,cnt-i);
	}
}

int main()
{
	//freopen("3.in","r",stdin);
	//freopen(".out","w",stdout);
	dfs(1,3);
	cout << ans << endl; 
	return 0;
}
