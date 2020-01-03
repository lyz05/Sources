#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n;

struct node
{
    int l,r;
}p[N];

bool cmp(node A,node B)
{
    return A.r<B.r;
}

int main()
{
    cin >> n;
    for (int i=1;i<=n;i ++)
    {
        cin >> p[i].l >> p[i].r;
    }
    sort(p+1,p+1+n,cmp);
    int ans = 0,now = -1e9+7;
    for (int i=1;i<=n;i ++)
    {
        if (now<p[i].l)
        {
            now = p[i].r;
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}