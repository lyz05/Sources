#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

int n;
int a[1005],ans = 0,k;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int tot;
		scanf("%d",&tot);
		for (int j=1;j<=tot;j ++) 
		{
			int t;
			scanf("%d",&t);
			a[t] ++; 
		} 
	}
	for (int i=1000;i;i --)
	{
		if (a[i]>ans)
		{
			ans = a[i];
			k = i;
		}
	}
	printf("%d %d\n",k,ans);
	return 0;
} 
