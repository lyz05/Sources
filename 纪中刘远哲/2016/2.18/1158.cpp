#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 20;
int n,m,minm;
int C[N],P[N],L[N];
    
int gcd(int a,int b,int c,int &x,int &y)
{
	if (!b)
	{
		x = c/a;
		y = 0;
		return a;
	}
	int ret = gcd(b,a%b,c,x,y),t = x;
	x = y;
	y = t-a/b*y;
	return ret;
}

int work(int a,int b,int c)
{
	int x,y;
	int g = gcd(a,b,c,x,y);
	if (c%g) return 1e9+7;
	//printf("%d %d\n",x,1*b/g);
	int z = abs(b/g);
	while (x<0) x += z;
	while (x>0 && x-z>0) x -= z;
	return x;
	//x = x + k*b/g
}

int main()
{
	freopen("1158.in","r",stdin);
	//freopen("1158.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{	
		scanf("%d%d%d",C + i,P + i,L + i);
		minm = max(minm,C[i]);
	}

	bool flag = 0;
	for (m = minm;!flag;m ++)
	{
		flag = 1;
		for (int i=1;i<=n && flag;i ++)
			for (int j=i+1;j<=n && flag;j ++)
			{
				int x = work(P[i]-P[j],m,C[j]-C[i]);
				flag = !(x<=min(L[i],L[j]));
				if (!flag) break;
			}
	}
	printf("%d\n",m-1);

	return 0;
}
