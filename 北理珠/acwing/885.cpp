#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long LL;

const int N = 2000+5,mo = 1e9+7;
int n,m;
LL a[N][N];

void init()
{
	a[1][1] = 1;
	for (int i=2;i<=N-4;i ++)
		for (int j=1;j<=i;j ++)
			a[i][j] = (a[i-1][j-1] + a[i-1][j])%mo;
}

int main()
{
	init();
	cin >> n;
	for (int i=1;i<=n;i ++) 
	{
		int x,y;
		cin >> x >> y;
		cout << a[x+1][y+1] << endl; 
	} 
	return 0;
} 
