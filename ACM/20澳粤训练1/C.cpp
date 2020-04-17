#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int T,ans,n,k;
int a[26];
string s;

int main()
{
    freopen("C.in", "r", stdin);
    //freopen(".out","w",stdout);

    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n >> k;
        cin >> s;
        for (int i = 1; i <= k / 2; i++)
        {
            int maxx = 0;
            memset(a, 0, sizeof a);
            for (int j = 0; j < n; j += k)
            {
                a[s[j + i - 1] - 'a']++;
                a[s[j + k - i] - 'a']++;
            }
            for (int j = 0; j < 26; j++)
                maxx = max(a[j], maxx);
            ans += n / k * 2 - maxx;
        }
        if (k % 2)
        {
            int maxx = 0;
            memset(a, 0, sizeof a);
            for (int j = 0; j < n; j += k)
            {
                a[s[j + k / 2] - 'a']++;
            }
            for (int j = 0; j < 26; j++)
                maxx = max(a[j], maxx);
            ans += n / k - maxx;
        }
        cout << ans << endl;
    }

    return 0;
}
