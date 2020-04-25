#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1e5 + 7;
int H[N];

int gf(int x)
{
    if (x == H[x])
        return x;
    else
        return H[x] = gf(H[x]);
}

bool link(int x, int y)
{
    int i = gf(x), j = gf(y);
    if (i == j)
        return 0;
    else
    {
        H[i] = j;
        return 1;
    }
}

int main()
{
    freopen("M.in", "r", stdin);
    //freopen(".out","w",stdout);
    int x, y, ans = 0;
    for (int i = 1; i <= 1e5 + 1; i++)
        H[i] = i;
    while (cin >> x >> y)
    {
        if (x == -1)
            break;
        if (!link(x, y))
            ans++;
    }
    cout << ans << endl;
    return 0;
}
