#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n=30,ans = 0;

void dfs(int dep,int last)
{
	if (dep>n)
	{
		ans ++;
		return;
	}
	for (int i=0;i<=1;i ++)
	{
		if (i==0) dfs(dep+1,i);
		if (i==1 && last==0) dfs(dep+1,i);
	}
}

int main()
{
	dfs(1,0);
	cout << ans << endl;
	return 0;
} 
