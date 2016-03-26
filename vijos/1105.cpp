#include <cstdio>
#include <cstring>

using namespace std;

const int N=200+2,oo=2105376125;

int n,p;
int c[N],u[N],v[N][N],e[N],o[N];


int main()
{
	freopen("1105.in","r",stdin);
	memset(v,125,sizeof v);
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++)
		scanf("%d %d",&c[i],&u[i]);
	for (int i=1;i<=p;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x][y]=z;
		e[y]++;
		o[x]++;
	}
	for (int i=1;i<=n;i++) 
		if (e[i]==0) u[i]=0;
	while (p>0)
	{
		for (int i=1;i<=n;i++)
			if (!e[i])
			{
				c[i]-=u[i];
				for (int j=1;j<=n;j++)
					if (v[i][j]!=oo)
					{
						if (c[i]>=0)
							c[j]+=v[i][j]*c[i];
						e[j]--;
						p--;
					}
			}
	}
	int flag=0;
	for (int i=1;i<=n;i++)
	{
		if (o[i]==0 && c[i]>0) {
			printf("%d %d\n",i,c[i]);
			flag=1;
		}
	}
	if (!flag) printf("NULL\n");
	return 0;
}
