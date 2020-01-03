#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1005; 
int n,pos,a[N],m;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	scanf("%d",&m);
	for (pos=1;pos<=n;pos ++) 
		if (a[pos]==m) break;
	if (pos==n+1) printf("-1"); else printf("%d",pos);
	return 0;	
} 

