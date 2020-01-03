#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<cstdlib>
#define pa pair<int,int>
#define inf 1000000000
#define linf 9000000000000000000LL
#define ll long long
using namespace std;
map <int,int> last;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
ll A,B,K;
ll a[2];

ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	freopen("data.in","r",stdin);
	T=read();
	while(T--)
	{
		last.clear();
		A=read();B=read();K=read();
		ll t=gcd(A,B);A/=t;B/=t;
		a[1]=A;last[a[1]]=1;
		for(int i=2;;i++)
		{
			a[i&1]=a[(i-1)&1]*K%B;
			if(a[i&1]==0)
			{
				printf("%d 0\n",i-1);
				break;
			}
			else if(!last[a[i&1]])last[a[i&1]]=i;
			else 
			{
				printf("%d %d\n",last[a[i&1]]-1,i-last[a[i&1]]);
				break;
			}
		}
	}
	return 0;
}
