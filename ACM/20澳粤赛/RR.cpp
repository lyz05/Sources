#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105;
int T,n;
int a[N];

int dfs(int dep)
{
    if (dep>n) {
        for (int i=1;i<=n;i ++)
        {
            if (a[i]==0 && (a[i-1]==1 || i==1) && (a[i+1]==1 || i==n)) return 1;
        }
        return 0;
    }
    int ret = 0;
    for (int i=0;i<2;i ++)
    {
        a[dep] = i;
            ret += dfs(dep+1);
        a[dep] = 0;
    }
    return ret;
}

int main()
{
    freopen("R.in", "r", stdin);
    //freopen(".out","w",stdout);
    cin >> T;
    while (T --){
        cin >> n;
        cout << dfs(1) << endl;
    }
    return 0;
}
