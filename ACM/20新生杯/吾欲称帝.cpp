#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 10000+5,dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}},MAX=2147483600;
char map[N][N];
int dis[N][N];
bool vis[N][N];
int SLlen,Alen,n;
struct Node{
    int x,y;
};
vector<Node> SL,A;

bool judge(Node A)
{
    if ((A.x>=1 && A.x<=n && A.y >= 1 && A.y <= n) && (map[A.x][A.y] == '.' || map[A.x][A.y] == 'E' || map[A.x][A.y] == 'A')) return 1; else return 0;
}

void bfs(Node now)
{
    memset(vis,0,sizeof vis);
    queue<Node> q;
    q.push(now);
    vis[now.x][now.y] = 1;
    dis[now.x][now.y] = 0;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        for (int i=0;i<4;i ++)
        {
            Node newNode;
            newNode.x = now.x+dir[i][0],newNode.y = now.y+dir[i][1];
            if (judge(newNode) && !vis[newNode.x][newNode.y]){
                vis[newNode.x][newNode.y] = 1;
                dis[newNode.x][newNode.y] = min(dis[newNode.x][newNode.y],dis[now.x][now.y]+1);
                q.push(newNode);
            }
        }
    }
}

int main()
{
    //freopen("0.in","r",stdin);
    //freopen("0.out","w",stdout);

    while (cin >> n)
    {
        SLlen = 0;
        Alen = 0;
        for (int i=1;i<=n;i ++)
            for (int j=1;j<=n;j ++)
            {
                dis[i][j] = MAX;
                Node now;
                cin >> map[i][j];
                now.x = i;
                now.y = j;
                if (map[i][j] == 'L' || map[i][j] == 'S')
                {
                    ++ SLlen;
                    SL.push_back(now);
                }
                if (map[i][j] == 'A')
                {
                    ++ Alen;
                    A.push_back(now);
                }
            }
        for (int i=0;i<SLlen;i ++) {
            bfs(SL[i]);
        }
        for (int i=0;i<Alen;i ++) {
            int ans = dis[A[i].x][A[i].y];
            ans = (ans>=MAX)?-1:ans;
            cout << ans << " ";
        }
    }

	return 0;
} 
/*
1
2 3
4 5 6 7
8 9 10 11 12 13 14 15
*/
