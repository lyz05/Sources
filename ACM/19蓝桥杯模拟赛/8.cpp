#include <iostream>
using namespace std;

const int N = 1004;
int dp[N][N];
int m, n;

int main()
{
    cin >> m >> n;
    //dp[i][j] (i&1==1) 表示前i个数中,第i个数在区间[j,n]的方案数
    //dp[i][j] (i&1==0) 表示前i个数中,第i个数在区间[1,j]的方案数
    //init
    for (int i = 1; i <= n; i++)
        dp[1][i] = n - i + 1;

    //procedure
    for (int i = 2; i <= m; i++)
        if (i & 1)//为奇数
            for (int j = n; j >= 1; j--)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j + 1]) % 10000;
        else
            for (int j = 1; j <= n; j++)
                dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % 10000;

    //print
    int ans = m & 1 ? dp[m][1] : dp[m][n];
    cout << ans;

    return 0;
}