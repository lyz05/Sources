#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int limit = 1e5;
bool p[limit+5];
int pri[10005];
int n,a0,a1,b0,b1;

void prepar()
{
	memset(p,0,sizeof p);
	for (int i=2;i<=limit;i ++)
	{
		if (!p[i])
		{
			p[i] = 1;
			pri[++ pri[0]] = i;
			for (int j=2;i*j<=limit;j ++) p[i*j] = 1;
		}
	}
}

void work(int &ret,int p)
{
	int a0c=0,a1c=0,b0c=0,b1c=0;
	while (a0%p==0) a0/=p,a0c++;
	while (a1%p==0) a1/=p,a1c++;
	while (b0%p==0) b0/=p,b0c++;
	while (b1%p==0) b1/=p,b1c++;
	if (a0c==a1c && b0c==b1c)
	{
		if (a1c<=b1c) ret*=b1c-a1c+1;
		else ret*=0;
	}
	if (a0c==a1c && b0c<b1c)
	{
		if (a1c<=b1c) ret *= 1;
		else ret *= 0;	
	}
	if (a0c>a1c && b0c==b1c)
	{
		if (a1c<=b1c) ret *= 1;
		else ret *= 0;
	}
	if (a0c>a1c && b0c<b1c)
	{
		if (a1c==b1c) ret *= 1;
		else ret *= 0;
	}
}

int calc()
{
	int ret = 1;
	for (int i=0;i<=pri[0];i ++)
	{
		work(ret,pri[i]);
	}
	if (a0!=1) work(ret,a0);else if (b1!=1 && a0!=b1) work(ret,b1);
	return ret;
}

int main()
{
	freopen("1753.in","r",stdin);
	//freopen("1753.out","w",stdout);

	prepar();
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		printf("%d\n",calc());
	}

	return 0;
}
