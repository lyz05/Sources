#include <cstdio>
using namespace std;

const int N = 99999+25;
int n,T;
bool p[N];

int main()
{
	freopen("7-4.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int tot;
		scanf("%d",&tot);
		if (tot==1) 
		{
			int t;
			scanf("%d",&t);
			continue;
		}
		for (int j=1;j<=tot;j ++)
		{
			int t; 
			scanf("%d",&t);
			p[t] = true;
		}
	}
	bool flag = 0;
	scanf("%d",&T);
	for (int i=1;i<=T;i ++)
	{
		int t;
		scanf("%d",&t);
		if (!p[t]) 
		{
			p[t] = 1;
			if (flag) printf(" "); 
			printf("%05d",t);
			flag = 1;
		}
	}
	if (!flag) printf("No one is handsome");
	return 0;
}
