#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105;
int T, n;
int dp[N][2][2];

int main()
{
    freopen("R.in", "r", stdin);
    //freopen(".out","w",stdout);
    dp[1][0][0] = 0;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    dp[1][1][1] = 0;
    for (int i = 2; i <= N - 5; i++)
    {
        dp[i][0][1] = dp[i-1][1][0] + dp[i-1][1][1];
        dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
        dp[i][1][1] = dp[i-1][1][1] + dp[i-1][0][1];
        dp[i][1][0] = dp[i-1][1][0] + dp[i-1][0][0];
    }
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << dp[n][0][1]+dp[n][1][1] << endl;
    }
    return 0;
}
