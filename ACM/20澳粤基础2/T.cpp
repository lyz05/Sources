#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

bool prime(int x)
{
    for (int i = 2; i <= floor(sqrt(x)); i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int main()
{
    cin >> n;
    for (int i = 4; i < n; i++)
    {
        if (!prime(i) && !prime(n - i))
        {
            cout << i << " " << n - i << endl;
            break;
        }
    }
    return 0;
}