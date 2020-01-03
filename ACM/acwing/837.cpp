#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
int n,m;
int h[N],Map[N];

int gf(int x)
{
	if (h[x]==x) return x;
	return h[x]=gf(h[x]);
}

void link(int x,int y)
{
	int i=gf(x),j=gf(y);
	if (i!=j)
	{
		h[i] = j;
        Map[j] = Map[i]+Map[j];
	}
} 

bool query(int x,int y)
{
	int i=gf(x),j=gf(y);
	return i==j;
}

int getnum(int x)
{
    return Map[gf(x)];
}

int main()
{
    cin >> n >> m;
    for (int i=1;i<=n;i ++) h[i] = i,Map[i] = 1;
    
    for (int i=1;i<=m;i ++)
    {
        string s;
        int x,y;
        cin >> s;
        if (s=="C")
        {
            cin >> x >> y;
            link(x,y);
        }
        if (s=="Q2")
        {
            cin >> x;
            cout << getnum(x) << endl;
        }
        if (s=="Q1")
        {
            cin >> x >> y;
            cout << (query(x,y)?"Yes":"No") << endl;
        }
    }
    return 0;
}