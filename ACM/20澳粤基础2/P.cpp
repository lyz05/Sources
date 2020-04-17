#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const char map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
LL n;
string s;
int r;

int main()
{
    while (cin >> n >> r)
    {
        s = "";
        bool flag = 0;
        if (n < 0)
            flag = 1,n = -n;
        while (n)
        {
            s = map[n % r] + s;
            n /= r;
        }
        if (flag) cout << "-";
        cout << s << endl;
    }
    return 0;
}