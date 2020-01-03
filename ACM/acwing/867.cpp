#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5+7;
int n,pri[N];

void resolve(int x)
{
	for (int i=2;i*i<=x;i ++)
	{
		if (x%i==0)
		{
			int cnt = 0;
			while (x%i==0) x/=i,cnt++;
			cout << i << " " << cnt << endl;
		}
	}
	if (x!=1) cout << x << " 1" << endl;
	cout << endl;
}

int main()
{
	freopen("867.in","r",stdin);
	cin >> n;
	for (int i=1;i<=n;i ++) 
	{
		int x; 
		cin >> x;
		resolve(x);
	} 

	return 0;
} 
