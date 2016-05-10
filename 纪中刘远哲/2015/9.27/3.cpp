#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

int gcd(int x,int y)
{
	while (y)
	{
		int z = x%y;
		x = y;y = z;
	}
	return x;
}

int main()
{
	freopen("czl.in","r",stdin);
	//freopen("czl.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T --)
	{
		scanf("%d",&n);
		int sum = 0,cnt = 0;
		for (int i=1;i<n;i ++)
			if (gcd(i,n)==1)
			{
				cnt ++;
				sum += i;
			}
		printf("%d %d\n",cnt,sum);
	}
	return 0;
}

