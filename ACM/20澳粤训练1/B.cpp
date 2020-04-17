#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int AN = 1e4 + 5, N = 1e4 + 5;
int a[AN], ans[N], tot, T, n;

int main()
{
    freopen("B.in", "r", stdin);
    //freopen(".out","w",stdout);
    cin >> T;
    while (T--)
    {
        memset(a, 0, sizeof a);
        tot = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int val;
            cin >> val;
            for (int j = 2; j <= val; j++)
            {
                if (val % j == 0)
                {
                    if (!a[j])
                    {
                        a[j] = ++tot;
                    }
                    ans[i] = a[j];
                    break;
                }
            }
        }
        cout << tot << endl;
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
