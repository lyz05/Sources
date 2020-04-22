#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

const int N = 10;
string s = "LANQIAO";
int len = 7, vis[N], a[N],ans;
map<string, bool> Map;

void dfs(int dep)
{
    if (dep > len)
    {
        string news = "";
        for (int i = 1; i <= len; i++)
            news += s[a[i]];
        Map[news] = 1;
        //cout << news << endl;
        ans ++;
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            a[dep] = i;
            dfs(dep + 1);
            a[dep] = 0;
            vis[i] = 0;
        }
    }
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);

    dfs(1);
    cout << Map.size() << endl << ans << endl;
    return 0;
}
