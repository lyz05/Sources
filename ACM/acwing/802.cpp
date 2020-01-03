#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;

const int N = 2e5+5;
int n,m;
LL sum[N];

struct Node
{
	LL val,num;
	LL x,y;
} b[N];
map <LL,Node> Map;

int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i ++) 
	{
		LL x,y;
		cin >> x >> y;
		Map[x].val += y;
	}
	for (int i=1;i<=m;i ++)
	{
		cin >> b[i].x >> b[i].y;
		Map[b[i].x].num = 0;
		Map[b[i].y].num = 0;
	} 
	map<LL,Node>::iterator it;
	int k;
	for (k=1,it=Map.begin();it!=Map.end();it ++,k ++)
	{
		(it->second).num = k;
		sum[k] = sum[k-1] + (it->second).val;
		//cout << it->first << "->" << (it->second).val << "->" << k << endl; 
	}
	for (int i=1;i<=m;i ++)
	{
		cout << sum[Map[b[i].y].num]-sum[Map[b[i].x].num-1] << endl;
	}
	return 0;
} 
