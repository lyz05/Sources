#include <iostream>
#include <string.h>
#include <string>
#include <map>

int a[200];
using namespace std;

int main() {

    int n;
    cin >> n;
    string s;
    for (int k = 0; k < n; k++) {
        memset(a, 0, sizeof(a));
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            a[s[i]]++;
            ans = max(ans, a[s[i]]);
        }
        cout << "Case #" << k + 1 << ": " << ans << endl;
    }

    return 0;
}
