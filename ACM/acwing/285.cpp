#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 6000+7;
int n,tot;
int f[N][2],a[N],e[N],rd[N];
struct Node
{
    int y,next;
} h[N];

void add(int x,int y)
{
    tot ++;
    h[tot].y = y;
    h[tot].next = e[x];
    e[x] = tot;
    rd[y] ++;
}

void dfs(int x)
{
    f[x][0] = 0;
    f[x][1] = a[x];
    for (int i=e[x];i;i = h[i].next)
    {
        int y = h[i].y;
        dfs(h[i].y);
        f[x][0] += max(f[y][1],f[y][0]);
        f[x][1] += f[y][0];
    }
    
}

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i];
	for (int i=1;i<n;i ++)
    {
        int x,y;
        cin >> x >> y;
        add(y,x);
    }
    for (int i=1;i<=n;i ++)
        if (!rd[i])
        {
            dfs(i);
            cout << max(f[i][0],f[i][1]) << endl;
            return 0;
        }
	return 0;
} 
