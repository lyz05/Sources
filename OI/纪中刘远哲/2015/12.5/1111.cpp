#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define maxn 15
#define mo 1000000007
#include<map>
#define m 10000007
using namespace std;

int a[maxn],n,tmp[maxn];

ll ans;

map<ll,ll> f[maxn];

ll dfs(ll);

ll calc(ll p,ll poi,ll now){
	if (p>n) {
		if (poi!=0)	return 0;
		else return dfs(now+1);
	}
	if (3*(n-p+1)<poi) return 0;
	ll ret=0;
	if (a[p]>=3) {
		a[p]-=3;
		ret=(ret+calc(p+1,poi,now)) % mo;
		a[p]+=3;
	}
	if (a[p]&&poi) {
		a[p]--;
		ret=(ret+calc(p+1,poi-1,now)) % mo;
		a[p]++;
	}
	if (poi>=3) ret=(ret+calc(p+1,poi-3,now)) % mo;
	return ret;
}

ll dfs(ll now){
	if (now==n) {
		if (a[n]==0) return 1;
		else return 0;
	}
	tmp[0]=0;
	fo(i,now,n) tmp[++tmp[0]]=a[i];
	//sort(tmp+1,tmp+tmp[0]+1);
	ll ha=0;
	fo(i,1,tmp[0]) ha=ha*29+tmp[i];
	if (f[now].find(ha)!=f[now].end()) return f[now][ha];
	return f[now][ha]=calc(now+1,a[now],now);
}

int main(){
	freopen("1110.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	//sort(a+1,a+n+1);
	ans=dfs(1);
	printf("%lld",ans);
	return 0;
}
