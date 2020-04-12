#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

map<char, int> a, b;
int T, n;

int main()
{
    freopen("D:\\git\\lyz05\\ACM\\20shuangbeibei\\F.in", "r", stdin);
    //freopen(".out","w",stdout);

    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        a.clear();
        b.clear();
        cout << "Case #" << t << ":" << endl;
        cin >> n;
        char ch;
        for (int i = 1; i <= n; i++)
        {
            cin >> ch;
            a[ch]++;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> ch;
            b[ch]++;
        }
        if (a['r'] != b['r'])
        {
            cout << "NO" << endl;
            continue;
        }
        a['w'] = a['w'] - b['t'], b['t'] = 0;
        b['w'] = b['w'] - a['t'], a['t'] = 0;
        if (a['w'] < 0 || b['w']<0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (a['i'] > b['f'] + b['w'] || a['f'] > b['i'] + b['w'] || a['w'] > b['f'] + b['i'])
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }

    return 0;
}
// ttfft
// wfwii