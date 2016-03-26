#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200000+5;

int n,a[N],x,y;

int main()
{
	freopen("1816.in","r",stdin);
	scanf("%d",&n);
	for (int i = 0;i < n;i ++)
	{
		scanf("%d",&a[i]);
	}
	
	sort(a,a + n);
	x = a[0];y = 1;
	for (int i = 1;i < n;i ++)
	{
		if (a[i] != x){
		       	printf("%d %d\n",x,y);
			x = a[i];
		       	y = 0;
		}
		y ++;
	}
	printf("%d %d\n",x,y);
	return 0;
}

