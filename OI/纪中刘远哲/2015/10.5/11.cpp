#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	freopen("suquare.in","r",stdin);
	freopen("suquare.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for (int k=1;k<=p;k ++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		for (int i=a[i].x1,i<=a[i].x2;i ++)
			for (int j=a[i].y1;j<=a[i].y2;j ++)
				map[i][j] = 1;
	}
	int l = 0,r = min(n,m)+1;
	for (len=l;len<=r;len ++)
	{
		bool p = 0;
		for (int i=1;i<=n;i ++)
		{
			for (int j=1;j<=m;j ++)
			{
				bool flag = 0;
				for (int x=0;x<len;x ++)
				{
					if (flag) break;
					for (int y=0;y<len;y ++)
					{
						if (map[i+x][j+y])
						{
							flag = 1;
							break;
						}
					}
				}
				if (!flag) {p = 1;break;}
			}
			if (p) break;
		}
		if (!p) break;
	}
	printf("%d\n",len-1);
	return 0;
}

