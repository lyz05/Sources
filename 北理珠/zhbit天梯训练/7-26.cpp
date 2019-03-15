#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int M = 10000+7;
map<string,bool> mymap;
struct node
{
	string name;
	int num;
} h[M];
int n,m,sum;

bool cmp(node A,node B)
{
	return A.name<B.name;
}

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
	 	string s; 
		cin >> s;
		mymap[s] = 1;
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i ++)
	{
		string s;
		int t;
		cin >> s >> t;
		h[i].name = s;
		h[i].num = t;
		sum += t;
	} 
	sum /= m;
	sort(h+1,h+1+m,cmp);
	bool flag = 0;
	for (int i=1;i<=m;i ++)
	{
		if (!mymap[h[i].name] && h[i].num>sum)
			cout << h[i].name << endl,flag = 1;
	}
	if (!flag) puts("Bing Mei You");
	return 0;
}
