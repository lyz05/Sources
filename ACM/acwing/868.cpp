#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e6+7;
int n,p[N],ans;

void init()
{
	for (int i=2;i<=N-5;i ++)
	{
		if (!p[i])
		{
			for (int j=2;i*j<=N-5;j ++) p[i*j] = 1;
		}
	}
}

int main()
{
	init();
	cin >> n;
	for (int i=2;i<=n;i ++) ans += (!p[i]);
	cout << ans << endl;
	return 0;
} 
