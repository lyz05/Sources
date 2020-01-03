#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 64+15;
int a[N],vis[N],tot,sum,n,maxx,initlen;


bool dfs(int num, int len,int s)
{
    if (num == cnt)
        return true;
    int same = -1;
    for (int i = s; i <= n; i++)
    {
        if (vis[i] || a[i] == same) 
            continue;
        vis[i] = true;
        if (len+a[i] < initlen)
        {
            if (dfs(num, len+a[i], i))
                return true;
            else
                same = stick[i];
        }
        else if (len+stick[i] == initlen)
        {
            if (dfs(num+1, 0, 0))
                return true;
            else
                same = stick[i];
        }
        vis[i] = false;
        if (len == 0)       //¼ôÖ¦4
            break;
    }
    return  false;
} 

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("A.in","r",stdin);
	//freopen(".out","w",stdout);
	while (cin >> n && n)
	{
		sum = 0;maxx = 0;
		for (int i=1;i<=n;i ++) cin >> a[i],sum += a[i],maxx = max(maxx,a[i]);
		sort(a+1,a+1+n,cmp);
		for (initlen = maxx;initlen <= sum;initlen ++)
		{
			if (sum%i) continue; 
			if (dfs(1,0,1))
			{
				cout << initlen << endl;
				break;
			}
		}
	}
	return 0;
}
