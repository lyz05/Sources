#include <cstdio>
#include<cmath>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;

const int N =15+5,now = 7,last=1;
int n,m,ans;
int map[N],Tmap[N],Ans[N*N][2],Tmp[N*N][2];

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("C.out","w",stdout);
	
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(map,0,sizeof map);
		memset(Tmp,0,sizeof Tmp);
		ans=INT_MAX;
		for (int i=1;i<=m;i ++)
		{
			for (int j=0;j<n;j ++)
			{
				int x;
				scanf("%d",&x);
				map[i] = map[i] + (x<<j);
			}
		}
		
		for (int x=0;x<(1<<n);x ++)
		{
			map[0] = x;
			int tmp = 0;
			memcpy(Tmap,map,sizeof map);
			for (int i=1;i<=m;i ++)
			{
				for (int j=0;j<n;j ++)
					if (Tmap[i-1]&(1<<j))
					{
						tmp ++;
						Tmp[tmp][0] = i,Tmp[tmp][1] = j;
						Tmap[i-1]^=(last<<j);
						Tmap[i+1]^=(last<<j);
						Tmap[i]^=(j-1>=0)?now<<(j-1):now>>(-(j-1));
				}
			}
			if ((Tmap[m]&((1<<n)-1))==0) 
				if (tmp<ans)
				{
					ans =tmp;
					memcpy(Ans,Tmp,sizeof Tmp);
				}
		}
		if (ans==INT_MAX) 
		{
			puts("IMPOSSIBLE");
			continue;
		}
		int tmp = 1;
		for (int i=1;i<=m;i ++,puts(""))
			for (int j=0;j<n;j ++)
				if (Ans[tmp][0]==i && Ans[tmp][1]==j && tmp<=ans){
					printf("1 ");
					tmp ++;
				}
				else printf("0 ");
	}
	return 0;
}