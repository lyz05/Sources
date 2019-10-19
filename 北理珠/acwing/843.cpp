#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10;
int n,a[N];
bool p[N];

bool judge(int m,int k)
{
	for (int i=1;i<m;i ++) 
		if (abs(m-i)==abs(a[i]-k)) return 0;
	return 1;
}

void print()
{
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=n;j ++)
			if (j==a[i]) cout << 'Q';
			else cout << '.';
		cout << endl;
	}
	cout << endl;
}

void dfs(int dep)
{
	if (dep>n)
	{
		print();
		return;
	}
	for (int i=1;i<=n;i ++)
	{
		if (!p[i] && judge(dep,i))
		{
			p[i] = 1;
			a[dep] = i;
				dfs(dep+1);
			a[dep] = 0;
			p[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	dfs(1); 
	return 0;
} 
