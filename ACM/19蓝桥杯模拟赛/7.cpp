#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int N = 1005;
int b[N][N];
int n, m, t;

int main()
{
    cin >> m >> n;
    int level = m / 2 + m % 2;
    for (int i = 0; i < level; i++)
    {
        for (int j = i; j <= n - 1 - i && t <= m * n - 1; j++)
            b[i][j] = ++t;
        for (int j = i + 1; j <= m - 2 - i && t <= m * n - 1; j++)
            b[j][n - 1 - i] = ++t;
        for (int j = n - i - 1; j >= i && t <= m * n - 1; j--)
            b[m - 1 - i][j] = ++t;
        for (int j = m - 2 - i; j >= i + 1 && t <= m * n - 1; j--)
            b[j][i] = ++t;
    }
    int r, c;
    cin >> r >> c;
    cout << b[r - 1][c - 1] << endl;
    return 0;
}
