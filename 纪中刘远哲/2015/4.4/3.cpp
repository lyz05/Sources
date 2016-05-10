#include <cstdio>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

int n,t;

int work(int n)
{
	list <int> mylist;
	int cnt,tot,level;

	for (int i=1;i<=n*(n+1)/2;i++) mylist.push_back(i);
	cnt = tot = 0;level = 1;
	
	while (mylist.size()>1)
	{
		list <int>::iterator i;
		for (i = mylist.begin();i != mylist.end();i++)
		{
			cnt ++;
			if (cnt == n+1-level)
			{
				tot ++;
				cnt = 0;
				i = mylist.erase(i);
				i--;
				if (mylist.size()==1) break;
			}
			if (tot == n+1-level)
			{
				tot = 0;
				level ++;
			}
		}
	}
	return mylist.back();
}

int main()
{
	freopen("3.in","r",stdin);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int ans = work(n);
		printf("%d\n",ans);
	}
	return 0;
}
