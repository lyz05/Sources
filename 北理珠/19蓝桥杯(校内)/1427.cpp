#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e7+5;
int f[N];

int main()
{
    //freopen("1004.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    f[0] = 1;
    for (int i=1;i<=n*m;i ++) 
    {
        if (f[i-n] && i-n>=0) f[i] = 1;
        if (f[i-m] && i-m>=0) f[i] = 1;
    }
    for (int i=n*m;i>=1;i --)
        if (!f[i])
        {
            printf("%d\n",i);
            break;
        }
    //for (int i=1;i<n*m;i ++)
    //    if (f[i]) printf("%d ",i);
}

