#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1000 + 10;
int n;
int x[N], y[N], r[N];
bool vis[N];
int ans, sum;

bool cal(int i)
{
    for (int j = 0; j < n; j++)
    {
        if (i != j && vis[j])
        {
            int dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (dis < (r[i] + r[j]) * (r[i] + r[j]))
                return 0;
        }
    }
    return 1;
}

void dfs(int dep)
{
    if (dep > n)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int tmp = r[i];
            if (!cal(i))
                r[i] = 0;
            vis[i] = 1;
            sum += r[i] * r[i];
            dfs(dep + 1);
            sum -= r[i] * r[i];
            vis[i] = 0;
            r[i] = tmp;
        }
    }
}

int main()
{
    freopen("10.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];
    dfs(1);
    printf("%d", ans);
    return 0;
}