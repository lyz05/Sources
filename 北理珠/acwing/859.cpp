#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5+5;
int n,m,h[N],ans;

struct Node
{
	int x,y,z;
} a[N];

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

bool cmp(Node A,Node B)
{
	return A.z<B.z;
}

bool judge()
{
	int flag = gf(1);
	for (int i=2;i<=n;i ++)
		if (flag!=gf(i)) return 0;
	return 1;	
}

int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i ++) h[i] = i;
	for (int i=1;i<=m;i ++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	sort(a+1,a+m+1,cmp);

	for (int i=1;i<=m;i ++)
	{
		if (!query(a[i].x,a[i].y))
		{
			link(a[i].x,a[i].y);
			ans += a[i].z;
		}
	}
	if (judge()) cout << ans << endl; else cout << "impossible" << endl;
	return 0;
} 
