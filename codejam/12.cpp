#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int M = 2505;
int T,n,p[M],flag[M];

int main()
{
	//freopen("12.in","r",stdin);
	//freopen("2.out","w",stdout);

	scanf("%d",&T);
	for (int k=1;k<=T;k ++)
	{
		memset(p,0,sizeof p);
		memset(flag,0,sizeof flag);
		scanf("%d",&n);
		for (int i=1;i<=2*n-1;i ++) 
			for (int j=1;j<=n;j ++)
			{
				int num = 0;
				scanf("%d",&num);
				p[num] = !p[num];
				flag[num] = 1;
			}
		printf("Case #%d: ",k);
		for (int i=1;i<=2500;i ++)
			if (p[i] && flag[i]) printf("%d ",i);
		puts("");
	}
	return 0;
}
