#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 200005;
int n,k,p,ans;
int col[N],col1[N];

int main()
{
	freopen("1737.in","r",stdin);
	//freopen("1737.out","w",stdout);

	scanf("%d%d%d",&n,&k,&p);
	for (int i=1;i<=n;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		col[x] ++;
		if (y<=p) 
		{
			ans += col[x]-1;
			for (int j=0;j<k;j ++) 
				col1[j] = col[j];
		} else ans += col1[x];
	}
	printf("%d\n",ans);

	return 0;
}
