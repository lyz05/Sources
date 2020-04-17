#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[205];
string ans;

int main()
{
    cin >> s;
    for (int i = 0; i < strlen(s);)
    {
        if (s[i]=='W' && s[i+1]=='U' && s[i+2]=='B') 
            i += 3;
        else {
            ans += s[i];
            i ++;
            if (s[i]=='W' && s[i+1]=='U' && s[i+2]=='B') {
                ans += ' ';
                i += 3;
            }
        }
    }
    cout << ans << endl;
    return 0;
}