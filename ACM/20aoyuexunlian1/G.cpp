#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef unsigned long long LL;

LL n, calc;

LL pow(LL x, LL y)
{
    LL ret = 1;
    for (LL i = 1; i <= y; i++)
        ret *= x;
    return ret;
}

int main()
{
    freopen("G.in", "r", stdin);
    //freopen(".out","w",stdout);

    while (cin >> n)
    {
        calc = 0;
        LL i;
        for (i = 1; pow(i, i) <= n && i<=15; i++);
        cout << (i - 1) << endl;
    }

    return 0;
}
