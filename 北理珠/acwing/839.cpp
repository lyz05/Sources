#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 1e5+7;
int n,m,tot,ph[N],hp[N],h[N];

void heap_swap(int x,int y)
{
    swap(h[x],h[y]);
    swap(hp[x],hp[y]);
    swap(ph[hp[x]],ph[hp[y]]);
}

void up(int u)
{
    while (u/2>0 && h[u]<h[u/2])
    {
        heap_swap(u,u/2);
        u/=2;
    }
}

void down(int u)
{
    int t = u;
    if (u*2<=tot && h[t]>h[u*2]) t = u*2;
    if (u*2+1<=tot && h[t]>h[u*2+1]) t = u*2+1;
    if (u!=t)
    {
        heap_swap(u,t);
        down(t);
    }
}

int main()
{
    freopen("839.in","r",stdin);
	cin >> n;
    while (n --)
    {
        string s;
        cin >> s;
        if (s=="PM")
        {
            cout << h[1] << endl;
        }
        if (s=="DM")
        {
            heap_swap(1,tot);
            tot --;
            down(1);
        }
        if (s=="I")
        {
            m ++;
            int x;
            cin >> x;
            h[++ tot] = x;
            ph[m] = tot;
            hp[tot] = m;
            up(tot);
        }
        if (s=="D")
        {
            int k;
            cin >> k;
            int u = ph[k];
            heap_swap(u,tot);
            tot --;
            up(u);
            down(u);
        }
        if (s=="C")
        {
            int k,x;
            cin >> k >> x;
            h[ph[k]] = x;
            down(ph[k]);
            up(ph[k]);
        }
    }
	return 0;
} 
