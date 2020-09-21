#include<cstdio>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 7;
string s;
int T;
int Map[256];

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int ans = 0;
        memset(Map, 0, sizeof Map);
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            Map[s[i]]++;
            ans = max(ans,Map[s[i]]);
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
