#include<iostream>
#include<cstdio>
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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,T;
int x[100005],y[100005];
int a[100005],b[100005];
ll s1[100005],s2[100005],ans;
void solve()
{
	ll t;
	if(T%n==0)
	{
		for(int i=1;i<=n;i++)	
			s1[i]=s1[i-1]+x[i];
		sort(s1+1,s1+n+1);
		t=s1[(n+1)>>1];
		for(int i=1;i<=n;i++)
			ans+=abs(t-s1[i]);
	}
	if(T%m==0)
	{
		for(int i=1;i<=m;i++)
			s2[i]=s2[i-1]+y[i];
		sort(s2+1,s2+m+1);
		t=s2[(m+1)>>1];
		for(int i=1;i<=m;i++)
			ans+=abs(t-s2[i]);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	
	n=read();m=read();T=read();
	for(int i=1;i</=T;i++)
	{
		int a=read(),b=read();
		x[a]++;y[b]++;
	}
	if(T%n&&T%m)
	{
		puts("impossible");
		return 0;
	}
	for(int i=1;i<=n;i++)x[i]-=T/n;
	for(int i=1;i<=m;i++)y[i]-=T/m;
	solve();
	if(T%n==0&&T%m==0)printf("both ");
	else if(T%n==0)printf("row ");
	else printf("column ");
	printf("%lld\n",ans);
	return 0;
}
