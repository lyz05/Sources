
#include<queue>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 20
using namespace std;
int n,map[20][20],f[1<<20];
bool vis[1<<20];
queue<long long>q;
int main()
{
	freopen("data.in","r",stdin);
	int m,i,j,k,now,t1,t2,y;
	scanf("%d",&n);
	for(i=1,k=0;i<=n;i++)
	{
		map[i][i]=0x3f3f3f3f;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&map[i][j]);
		}
		k=(k|1)<<1;
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	vis[0]=1;
	q.push(0);
	while((now=q.front())!=k)
	{
		q.pop();
		i=1,t1=now;
		bool flag = q.empty();
		while(i<n)
		{
			while(t1&2)
			{
				t1>>=1;
				i++;
			}
			t2=t1>>1;
			for(j=i+1;j<=n;j++)
			{
				if((t2&2)==0)
				{
					//if (f[now]>100000000) continue;
					f[y=(now|(1<<i)|(1<<j))]=min(f[y],f[now]+map[i][j]);
					if(vis[y]==0)
					{
						vis[y]=1;
						q.push(y);
					}
				}
				t2>>=1;
			}
			t1>>=1;
			i++;
		}
	}
	printf("%d",f[k]);
}
