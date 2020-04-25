#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int dp[45],n;

int main()
{
	freopen("Q.in","r",stdin);
	//freopen(".out","w",stdout);

    while (cin >> n) {
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3;i<=n;i ++)
        dp[i] = dp[i-1]+dp[i-2];
        cout << dp[n] << endl;
    }

	return 0;
}
