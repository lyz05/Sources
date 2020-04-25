#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1024 + 2;
int n, tot;

struct Node
{
    int num;
    int id;
} h[N * N];

int calc(int x, int y)
{
    int ret = 0, cnt = 0;
    while (x || y)
    {
        ret = ret + ((y % 2) << cnt);
        cnt++;
        y /= 2;
        ret = ret + ((x % 2) << cnt);
        cnt++;
        x /= 2;
    }
    return ret;
}

bool cmp(Node A, Node B)
{
    return A.id < B.id;
}

int main()
{
    freopen("N.in", "r", stdin);
    //freopen(".out","w",stdout);
    //cout << calc(2,8) << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> h[++tot].num;
            h[tot].id = calc(i, j);
        }
    sort(h + 1, h + 1 + tot, cmp);

    h[tot + 1].num = 1e9 + 7;
    for (int i = 1, cnt = 0; i <= tot; i++)
    {
        if (h[i].num == h[i + 1].num)
        {
            cnt++;
        }
        else
        {
            cnt++;
            cout << h[i].num << "," << cnt << " ";
            cnt = 0;
        }

        //cout << h[i].num << " ";
    }

    return 0;
}
