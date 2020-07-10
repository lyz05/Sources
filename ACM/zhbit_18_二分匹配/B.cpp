#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int M = 1000 + 5;
int n, m, k, cas;
int link[M];
bool MAP[M][M];
bool cover[M];
int ans;

void init()
{
    int x, y;
    memset(MAP, false, sizeof(MAP));
    for(int i=0; i<k; i++)
    {
        scanf("%d %d %d", &cas, &x, &y);
        if(x&&y)
        MAP[x][y]=true;
    }
}

bool dfs(int x)
{
    for(int y=1; y<=m; y++)
    {
        if(MAP[x][y] && !cover[y])
        {
            cover[y]=true;
            if(!link[y] || dfs(link[y]))
            {
                link[y]=x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    while(scanf("%d", &n) && n)
    {
        ans=0;
        memset(link, 0, sizeof(link));
        scanf("%d %d", &m, &k);
        init();
        for(int i=1; i<=n; i++)
        {
             memset(cover, false, sizeof(cover));
             if(dfs(i))
                ans++;
        }
       printf("%d\n", ans);
    }

    return 0;
}
