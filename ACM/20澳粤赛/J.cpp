#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int map[2][9] = {{4, 0, 1, 2, 5, 8, 7, 6, 3}, {0, 3, 4, 5, 6, 7, 8, 1, 2}};
char s[12];
int n;

int calc(char s[])
{
    int ret = 0;
    for (int k = 1; k <= 8; k++)
        ret += ((s[0] - '0') ^ (s[k] - '0')) * (1 << (8 - k));
    return ret;
}

void transfer(char s[], const int map[])
{
    char news[12] = "";
    for (int i = 0; i < 9; i++)
        news[i] = s[map[i]];
    strcpy(s, news);
}

int main()
{
    freopen("J.in", "r", stdin);
    //freopen(".out","w",stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ans = 1e9 + 7;
        cin >> s;
        //cout << s << endl;
        transfer(s, map[0]);
        //cout << s << endl;
        //cout << calc(s) << endl;
        ans = min(ans, calc(s));
        for (int j = 1; j <= 3; j++)
        {
            transfer(s, map[1]);
            //cout << s << endl;
            //cout << calc(s) << endl;
            ans = min(ans, calc(s));
        }
        cout << ans << endl;
    }

    return 0;
}
