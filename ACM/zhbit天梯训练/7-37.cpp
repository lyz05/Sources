#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1e4+7,M = 16;
int n,a[N],ans,minn = 1e9+7;
char name[N][M];
double sum = 0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		scanf("%s %d",name[i],a+i);
		sum += a[i];
	}
	sum /= 2*n;
	printf("%d ",(int)floor(sum));
	for (int i=1;i<=n;i ++)
	{
		if (abs(sum-a[i])<minn) 
		{
			minn = abs(sum-a[i]);
			ans = i;
		}
	}
	printf("%s\n",name[ans]);
	return 0;
} 
