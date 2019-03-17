#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 105,M = 10+3;
int a[N];
int map[N][M][M];
int tot,n,maxx = 0,flag;

int main()
{
	freopen("7-31.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
	{
		scanf("%d",a+i);
		maxx = max(a[i],maxx);
	}
	//if (maxi==0) maxi = maxx;
	
	for (int j=1;j<=maxx;j ++)
	{
		for (int k=1;k<=10;k ++)
		{
			for (int i=1;i<=n;i ++)
			{
				if (a[i]<j) continue;
				if (i==flag) tot +=2; else tot ++;
				map[i][j][k] = tot;
				flag = i;
			}
		}
	}
	
	for (int i=1;i<=n;i ++)
	{
		printf("#%d\n",i);
		for (int j=1;j<=a[i];j ++)
		{ 
			for (int k=1;k<=10;k ++)
			{
				printf("%d",map[i][j][k]);
				if (k<10) printf(" ");
			}
			puts("");
		}
	}
	return 0;
}
