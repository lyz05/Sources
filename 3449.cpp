#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 110000;
int a[N],g[N],P,A,p,w[N],n,m,ans[N],cnt,Fac;

struct node
{
	int v,t;
	node (int _v = 0, int _t = 0) {v = _v , t = _t;}
};

node operator * (node x , node y) 
{
	return node((LL)x.v * y.v % p,x.t + y.t);
}

void decompose(int x)
{
	cnt = 0;
	for (int i = 2; i*i <= x ; i++)
		if (x % i == 0)
		{
			a[++ cnt] = i; g[cnt] = 1;
			for (; x % i == 0;x /= i) g[cnt] *= i;
		}
	if (x>1) {a[++ cnt] = x; g[cnt] = x;}
}

void exgcd(int a,int b,int &x,int &y)
{
	if (b==0) 
	{
		x = 1; y = 0; return;
	} 
	int tx,ty;
	exgcd(b ,a % b , tx , ty);
	x = ty;
	y = tx - (a/b) * ty;
}

int inverse(int x,int y)
{
	int a,b;
	exgcd(x , y , a , b);
	return (a + y) % y;
}

int power(int x, int y, int p)
{
	if (y==0) return 1;
	int tmp = power(x,y >> 1,p);
	tmp = (LL) tmp * tmp % p;
	if (y & 1) tmp = (LL) tmp * x % p;
	return tmp;
}

node calc(int x)
{
	node ret(1 , 0);
	int res = x % A;
	for (int i=x-res+1;i <= x ; i++) ret.v = (LL) ret.v*i % p;

	if (x >= A)
	{
		node tmp = calc(x / A);
		ret.t = tmp.t + x/A;
		ret.v = (LL)ret.v * tmp.v % p;
		ret.v = (LL)ret.v * power(Fac, x / A , p) % p;
	}
	return ret;
}

int main()
{
	//freopen("3449.in","r",stdin);

	scanf("%d",&P);
	scanf("%d%d",&n,&m);
	w[m+1] = n;
	for (int i = 1 ; i <= m; i++)
		scanf("%d",&w[i]),w[m+1] -= w[i];
	if (w[m+1]) ++m;
	decompose(P);

	for (int i = 1;i <= cnt; i ++)
	{
		A = a[i] , p = g[i] , Fac = 1;
		//A=pi,p=pi^ci
		for (int j = 2; j < A ; j ++)
			(Fac *= j) %= p;
		
		node cur,now;//分子与分母
		cur = calc(n);
		now = node(1,0);

		for (int j=1; j <= m ; j++) now = now * calc(w[j]);
		now.v = inverse(now.v , p);
		now.t *= -1;
		cur = cur * now;
		
		ans[i] = (LL) cur.v * power(A,cur.t,p) % p;
	}

	LL sum = 0;
	for (int i = 1 ; i <= cnt ; i ++)
	{
		sum = (sum + LL(ans[i]) * (P / g[i]) * inverse((P / g[i]) % g[i] , g[i])) % P;
	}
	//中国剩余定理
	printf("%lld\n",sum);
	
	return 0;
}
