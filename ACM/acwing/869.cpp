#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 2e6+5;
int n,ans[N];

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) 
	{
		ans[0] = 0;
		int x;
		cin >> x;
		for (int i=1;i<=floor(sqrt(x));i ++)
			if (x%i==0) 
				cout << i << " ",
				(x/i!=i)?ans[++ans[0]] = x/i:0;
		for (int i=ans[0];i;i --)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
} 
