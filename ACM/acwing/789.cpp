#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10000+7;
int n,m,a[N][2];

int main()
{
	cin >> n >> m;
	for (int i=0;i<=N-5;i ++) 
		a[i][0] = a[i][1] = -1;
	for (int i=0;i<n;i ++)
	{
		int t;
		cin >> t;
		if (a[t][0]==-1) a[t][0] = i;
		a[t][1] = i;
	}
	for (int i=1;i<=m;i ++)
	{
		int t;
		cin >> t;
		cout << a[t][0] << " " << a[t][1] << endl;
	}
	return 0;
} 
