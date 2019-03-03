#include <cstdio>
#include <algorithm>
using namespace std;

int n,m; 

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=m;j ++)
		{
			printf("%c",'A'+abs(i-j));
		}
		puts("");
	}
	
	return 0;	
} 
//1 1 2 3 5 8 13
