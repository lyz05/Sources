#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 205;
int n,a[N];

bool cmp(int x,int y)
{
	return x<y;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
		scanf("%d",a + i);
	sort(a+1,a+n+1,cmp);
	
	for (int i=1;i<n;i ++)
		printf("%d ",a[i]);
	printf("%d",a[n]);
	return 0;	
} 
//1 1 2 3 5 8 13
