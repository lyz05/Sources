#include <cstdio>
#include <algorithm>
#include <cstring>
#include <list>
using namespace std;

int n,m,k,now;
list <int> lis;

int main()
{
	freopen("data.in","r",stdin);
	freopen("3.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{

	scanf("%d%d%d",&n,&m,&k);
	lis.clear();
	lis.push_back(0);
	int tot1 = 0 , tot2 = 1;
	for (int now = 1;now<=n;now ++)
	{
		int len = lis.size() , cnt = 0;
		while (!lis.empty() && now-lis.front()==m) 
		{
			cnt ++;
			tot1 ++;
			lis.pop_front();
		}
		int j = min(len-cnt,k-len);
		tot2 += j;
		for (int i=1;i<=j;i ++) lis.push_back(now);
		printf("%d %d %d\n",tot1,tot2,tot2-tot1);
	}
	int len = lis.size();
	printf("%d\n",len);
	
	}
	return 0;
}
