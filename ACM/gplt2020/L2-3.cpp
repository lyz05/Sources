#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

const int N = 35;
int n,tot;
int a[N],h[N];

void dfs(int id)
{
	if (id>n) 
		return;
	dfs(id*2);
	dfs(id*2+1);
	h[id]=a[++ tot];
}

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++)
		cin >> a[i];
	dfs(1);
	for (int i=1;i<n;i ++)
		cout << h[i] << " ";
	cout << h[n];
	return 0;
}
