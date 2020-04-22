#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 1005, inf = 1e9 + 7;
int n, tot, h[N];
double ans = 0;
struct Point //点
{
    double x, y, h;
} p[N];
struct Edge //边
{
    int x, y;
    double val;
} e[N * N];

bool cmp(Edge x, Edge y)
{
    return x.val < y.val;
}
int gf(int x)
{
    if (x == h[x])
        return x;
    else
        return h[x] = gf(h[x]);
}

bool judge(int x, int y)
{
    int i = gf(x), j = gf(y);
    return i != j;
}

void add(int x, int y)
{
    int i = gf(x), j = gf(y);
    h[i] = j;
}

int main()
{
    //init
    freopen("9.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y >> p[i].h;

    //枚举出所有的边
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            double x, y, h;
            x = (p[i].x - p[j].x) * (p[i].x - p[j].x);
            y = (p[i].y - p[j].y) * (p[i].y - p[j].y);
            h = (p[i].h - p[j].h) * (p[i].h - p[j].h);
            e[++tot].val = sqrt(x + y) + h;
            e[tot].x = i;
            e[tot].y = j;
        }
    }
    //最小生成树
    sort(e + 1, e + 1 + tot, cmp);
    for (int i = 1; i <= n; i++)
        h[i] = i;
    for (int i = 1; i <= tot; i++)
    {
        if (judge(e[i].x, e[i].y))
        {
            ans += e[i].val;
            add(e[i].x, e[i].y);
        }
    }
    printf("%.2f", ans);
    return 0;
}