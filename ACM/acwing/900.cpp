#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int N = 1000+7,mo = 1e9+7;
int n,f[N];

int main()
{
    cin >> n;
    f[0] = 1;
    for (int i=1;i<=n;i ++)
        for (int j=i;j<=n;j ++)
            f[j] = (f[j] + f[j-i])%mo;
    cout << f[n] << endl;
	return 0;
}
