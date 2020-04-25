#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1e6 + 7;
struct Node
{
    int x, y;
} h[N];
int n;

bool cmp(Node A, Node B)
{
    return A.y > B.y;
}

int main()
{
    freopen("K.in", "r", stdin);
    //freopen(".out","w",stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i].x >> h[i].y;
    }
    sort(h, h + n, cmp);
    int ans = 0, now = 0;
    for (int i = 0; i < n; i++)
    {
        now += h[i].x;
        ans = max(ans, now + h[i].y);
    }
    cout << "Project " << n << ": " << ans << endl;
    return 0;
}
