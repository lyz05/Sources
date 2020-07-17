
#include <iostream>
#include <deque>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
using namespace std;
 
typedef long long int ll;
const int MAXN = 505;
 
vector<int> G[MAXN];
int N, M;
 
//ÐÙÑÀÀûËã·¨
bool vis[MAXN];
int Y[MAXN];
bool hungry(int x)
{
    for (int i = 0; i < G[x].size(); i++)
    {
        if (vis[G[x][i]] == 0)
        {
            vis[G[x][i]] = 1;
            if (Y[G[x][i]] == -1 || hungry(Y[G[x][i]]))
            {
                Y[G[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}
 
int main()
{
    int t;
    scanf("%d", &t);
 
    while (t--)
    {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i++)
        {
            G[i].clear();
        }
        int a, b;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
        }
 
        int ans = 0;
        memset(Y, -1, sizeof(Y));
        for (int i = 1; i <= N; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (hungry(i))
                ans++;
        }
 
        printf("%d\n", N - ans);
    }
 
    return 0;
} 
