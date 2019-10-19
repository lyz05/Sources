#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
int n,a[N];

int lowbit(int x)
{
	return x&(-x);
}

void modify(int x)
{
	while (x<=n)
	{
		
	}
}

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i];
	for (int i=n;i>=1;i --)
	{
		ans += query(a[i]);
		modify(a[i]);
	}
	return 0;
} 
