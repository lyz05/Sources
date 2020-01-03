#include <cstdio>
#include <algorithm>
#include <cstring>
#include <list>
using namespace std;

int n,m,k,now;
list <int> lis;

int main()
{
	freopen("horrible.in","r",stdin);
	freopen("horrible.out","w",stdout);
	
	//int T;
	//scanf("%d",&T);
	//while (T --)
	//{

	scanf("%d%d%d",&n,&m,&k);
	//lis.clear();
	lis.push_back(0);
	for (int now = 1;now<=n;now ++)
	{
		int len = lis.size() , cnt = 0;
		while (!lis.empty() && now-lis.front()==m) 
		{
			cnt ++;
			lis.pop_front();
		}
		int j = min(len-cnt,k-len);
		for (int i=1;i<=j;i ++) lis.push_back(now);
	}
	int len = lis.size();
	printf("%d\n",len);
	
	//}
	return 0;
}
