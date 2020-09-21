#include<cstdio>
#include<algorithm>
#include <iostream>
using namespace std;

const int N = 120;
int T,ans,n;
int a[N];

int main()
{
    cin >> T;
    while (T --){
        bool flag = 1;
        ans = 0;
        cin >> n;
        for (int i=1;i<=n;i ++)
            cin >> a[i];
        for (int i=2;i<=n;i ++)
            if (a[i]==a[i-1])
                flag = 0;
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}