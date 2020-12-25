#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 100+5;
int n,m,k,ans;
int a[N],map[N][N];
bool vis[N];

void dfs(int x,int len,int dis)
{
    if (len==k) {
        dis += map[x][1];
        ans = min(dis,ans);
        return;
    }
    for (int i=1;i<=k;i ++)
    {
        int y = a[i];
        if (!vis[i]) {
            vis[i] = 1;
            dfs(y,len+1,dis+map[x][y]);
            vis[i] = 0;
        }
    }
}

int main()
{
    freopen("0.in","r",stdin);
    int T;
    cin >> T;
    while (T --) {
        ans = 1e9+7;
        memset(vis,0,sizeof vis);
        cin >> n >> m;
        cin >> k;
        for (int i=1;i<=k;i ++) cin >> a[i];
        for (int i=1;i<=n;i ++)
            for (int j=1;j<=n;j ++)
                map[i][j] = 1e9+7;
        for (int i=1;i<=m;i ++)
        {
            int x,y,z;
            cin >> x >> y >> z;
            map[x][y] = min(map[x][y],z);
            map[y][x] = min(map[y][x],z);
        }
        for (int k=1;k<=n;k ++)
            for (int i=1;i<=n;i ++)
                for (int j=1;j<=n;j ++)
                    map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
        dfs(1,0,0);
        cout << ans << endl;
    }
    return 0;
} 
/*
1
2 3
4 5 6 7
8 9 10 11 12 13 14 15
*/
