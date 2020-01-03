#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

const int M = 7+5;
int n,ans,len = 6;
int a[M],b[5004+5];

void dfs(int dep)
{
	if (dep>len)
	{
		//for (int i=1;i<=len;i ++) cout << a[i];
		//cout << endl;
		int tmp = 0;
		for (int i=1;i<=len;i ++) tmp=tmp*10+a[i];
		b[++ b[0]] = tmp;
		return;
	}
	for (int i=a[dep-1];i<=9;i++)
	{
		a[dep] = i;
			dfs(dep+1);
		a[dep] = 0;
	}
}

int main()
{
	//freopen("5.in","r",stdin);
	//freopen("5.out","w",stdout);
	dfs(1);
	int i;
	b[b[0]+1] = 1e9+7;
	cin >> n;
	for (i=1;i<=b[0];i ++)
		if (b[i]>n) break;
	cout << i-2;
	return 0;
}
