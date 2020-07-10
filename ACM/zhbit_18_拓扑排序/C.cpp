#include <stdio.h>
#include <string.h>
#define N 510
int map[N][N] ,in[N];
bool vis[N] ;
int main()
{
	int n ,m;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		memset(in,0,sizeof(in)) ;
		memset(map,0,sizeof(map));
		memset(vis,false,sizeof(vis));
		for(int i = 0;i < m;i ++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(map[x][y] == 0) 
			{
				map[x][y] = 1 ;
				in[y]++ ;
			}
		}
		for(int i = 0 ; i < n ;i ++)
		{
			int ans = 0 ;
			for(int j = 1 ; j <= n ; ++j)
			{
				if(!vis[j] && in[j] == 0)
				{
					ans = j ;
					vis[j] = true ;
					break; 
				}
			}
			for(int j = 1 ; j <= n ; ++j)
			{
				if(map[ans][j] == 1)
				{
					in[j]--;
					map[ans][j] = 0 ;
				}
			}
			printf("%d",ans);
			if(i != n-1)
			{
				printf(" ") ;
			}
		}
		printf("\n") ;
	}
	return 0 ;
}
