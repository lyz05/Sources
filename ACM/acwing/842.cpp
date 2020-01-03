#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10;
int n,a[N];
bool p[N];

void print()
{
	for (int i=1;i<=n;i ++) cout << a[i] << " ";
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
		if (!p[i])
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
