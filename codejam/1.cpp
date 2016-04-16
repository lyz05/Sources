#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n,T,cnt;
bool h[10];
int work(int x)
{
	int i,now = 0;
	memset(h,0,sizeof h);
	cnt = 0;

	for (i=1,now=x*i;;i ++,now=x*i)
	{
		for (;now;now/=10) 
			if (!h[now%10]) 
				h[now%10] = 1,cnt ++;
		if (cnt==10) return x*i;
	}
	
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);

	scanf("%d",&T);
	for (int i=1;i<=T;i ++)
	{
		scanf("%d",&n);
		if (n==0) printf("Case #%d: INSOMNIA\n",i);
		else printf("Case #%d: %d\n",i,work(n));
	}

	return 0;
}
