 
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 50000+5;
int n, ans, sum;
struct node
{
    int s,w;
} h[N];

bool cmp(node A,node B)
{
    return A.s+A.w<B.s+B.w;
}

int main()
{
    ans = -1e9+7;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i].w >> h[i].s;
	}
    sort(h+1,h+1+n,cmp);
    for (int i=1;i<=n;i ++)
    {
        ans = max(ans,sum-h[i].s);
        sum += h[i].w;
    }
	cout << ans << endl;
}
