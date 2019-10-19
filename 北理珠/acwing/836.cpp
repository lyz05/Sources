#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
int n,m,h[N]; 

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
	}
} 

bool query(int x,int y)
{
	int i=gf(x),j=gf(y);
	return i==j;
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i ++) h[i] = i;
	while (m --) 
	{
		char c;
		int x,y;
		cin >> c >> x >> y;
		if (c=='M') link(x,y);
		else cout << (query(x,y)?"Yes":"No") << endl;
	} 
	return 0;
} 
