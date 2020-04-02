#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
LL n;
int a[1000];

int main()
{

    while (cin >> n)
    {
        cout << ((n & 1) ? (-(n/2+1)) : (n / 2)) << endl;
    }
    return 0;
}