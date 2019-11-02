#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010;
int n,ans,r[N];
priority_queue<int,vector<int>,greater<int> > q;
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
    cin >> n;
    for (int i=1;i<=n;i ++)
    {
        cin >> p[i].l >> p[i].r;
    }
    sort(p+1,p+1+n,cmp);
    
    for (int i=1;i<=n;i ++)
    {
        if (q.empty() || q.top()>=p[i].l) q.push(p[i].r);
        else
        {
            q.pop();
            q.push(p[i].r);
        }
        
    }
    cout << q.size() << endl;
    return 0;
}