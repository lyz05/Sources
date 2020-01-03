#include<cstdio>
#include<cstring>
#include<iostream>
#define ms(x,y) memset(x,y,sizeof(x))
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;

const int N = 105;
int n , m , K;
int a[N];
ll f[N][5*N];

void Init()
{
	scanf("%d%d%d",&n,&m,&K);
	fo(i,1,n) 
	{
		int x;
		scanf("%d",&x);
		++a[x];
	}
}

ll min(ll x,ll y){if (x<y) return x;else return y;}

ll get(ll x)
{
	return (1+x)*x >> 1;
}

ll get(int x,int k)
{
	k++;
	if (k>=x) return x;
	ll t = x % k , t1 = x/k;
	return t*get(t1+1) + (k-t)*get(t1);
}

void Work()
{
	ms(f,60);
	fo(j,0,K) f[1][j] = get(a[1] , j);
	fo(i,2,m)
		fo(j,0,K)
			fo(k,0,j)
			f[i][j] = min(f[i][j] , f[i-1][j-k] + get(a[i] , k));
	//rintf("%lld\n",f[m][K]);
	cout<<f[m][K]<<endl;
}

int main()
{
	/*freopen("noise.in","r",stdin); freopen("noise.out","w",stdout);*/
	
	Init();
	Work();
	
	return 0;
}
