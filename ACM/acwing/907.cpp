#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010;
int n,ans,s,t;
struct node
{
    int l,r;
}p[N];

bool cmp(node A,node B)
{
    return A.l<B.l;
}

int main()
{
    cin >> s >> t;
    cin >> n;
    for (int i=1;i<=n;i ++)
    {
        cin >> p[i].l >> p[i].r;
    }
    sort(p+1,p+1+n,cmp);
    
    for (int i=1;i<=n;i ++)
    {
        int r = -1e9+7,j;
        for (j=i;j<=n && p[j].l<=s;j ++)
        {
            r = max(r,p[j].r);
        }
        ans ++;
        if (r<s)
        {
            ans = -1;
            break;
        }
        if (r>=t)
        {
            break;
        }
        s = r;
        i = j-1;
    }
    cout << ans << endl;
    return 0;
}