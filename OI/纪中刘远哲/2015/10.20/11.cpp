#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int dir[6][3]={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
const int N = 150000+5,oo=2105376125;
int n,ans,a[5][N],f[2][10][5];

int main()
{
	//freopen("acm.in","r",stdin);
	//freopen("acm.out","w",stdout);

	scanf("%d",&n);
	for (int j=1;j<=3;j ++)
		for (int i=1;i<=n;i ++) 
			scanf("%d",&a[j][i]);
	

	ans = oo;
	memset(f,125,sizeof f);
	f[0][1][1] = a[1][1];
	f[0][2][2] = a[2][1];
	f[0][4][3] = a[3][1];
	for (int k=2,p=0,q=1;k<=n;k ++,p^=1,q^=1)
	{
		for (int i=0;i<=(1<<3)-1;i ++)
			for (int j=1;j<=3;j ++)
			{
				if (1<<(j-1) & i) 
				{
					int &now = f[q][i][j],&last = f[p][i][j];
					if (last!=oo)
						now = last+a[j][k];
					int ii = i ^ (1<<(j-1));
					for (int jj=1;jj<=3;jj ++)
					if (ii & (1<<(jj-1)))
					{
						int &last = f[p][ii][jj];
						if (last==oo) continue;
						now=min(now,last+a[j][k]);
					}
					if (k==n && i==7) ans = min(ans,now);
				}
			}
	}
	printf("%d\n",ans);

	return 0;
}


