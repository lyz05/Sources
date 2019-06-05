#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue< int,vector <int>,greater<int> > a;

int n;

int main()
{
	while (~scanf("%d",&n))
	{
		while (!a.empty()) a.pop();
		for (int i=1;i<=n;i ++)
		{
			int t;
			scanf("%d",&t);
			a.push(t);
		}
		long long ans = 0;
		for (int i=1;i<n;i ++)
		{
			int t1,t2,t;
			t1 = a.top(),a.pop();
			t2 = a.top(),a.pop();
			t = t1+t2;
			ans += t;
			a.push(t);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
