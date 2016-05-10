#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 10+5;

typedef long long LL;
LL A,B,ans;
LL f[N][10],t[N];

LL get(LL x)
{
	int len = 1,num = x%10,last = 0;
	LL ret = 0;
	while (t[len]<=x) 
		len ++;
	len --;
	for (int i=1;i<len;i ++)
		for (int j=1;j<=9;j ++) ret += f[i][j];
	
	num = x/t[len];
	for (int j=1;j<num;j ++) ret += f[len][j];
	x %= t[len];
	last = num;
	for (int i=len-1;i;i --)
	{
		num = x/t[i];
		for (int j=0;j<num;j ++)
			if (abs(last-j)>=2) ret += f[i][j];
		if (abs(num-last)<2) break;
		last = num;
		x %= t[i];
	}
	return ret;
}

void pre()
{
	t[1] = 1;
	for (int j=2;j<N;j ++) t[j] = t[j-1]*10;
	for (int j=0;j<=9;j ++) f[1][j] = 1;

	for (int i=2;i<=N-5;i ++)
	for (int j=0;j<=9;j ++)
	for (int k=0;k<=9;k ++)
		if (abs(j-k)>=2)
			f[i][j] += f[i-1][k];
}

int main()
{
	freopen("1039.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%lld%lld",&A,&B);
	pre();
	ans = get(B+1)-get(A);
	printf("%lld\n",ans);
	return 0;
}
