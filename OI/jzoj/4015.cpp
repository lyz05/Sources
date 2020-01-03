#include<cstdio>

int tt;
long long x,m,a,b,c,x0,n,i,zs,ans1,ans2;
int s[1100000];

long long fast(long long ds,long long cs,long long mod) {
	if (cs==1) return ds%mod;
	long long re=fast(ds,cs/2,mod);
	if (cs%2==0) return (re*re%mod);else return (re*re%mod*ds%mod);
}

int main() {
	scanf("%lld%lld%lld%lld%lld%lld",&x0,&a,&b,&c,&n,&m);
	x0%=m;
	a%=m;
	b%=m;
	c%=m;
	x=x0; 
	if (m<=1000000) {
		tt=1;
		s[x0]=1;
		for (i=1;i<=n;i++) {
			x=(((a*x)%m*x)%m+b*x%m+c)%m;
			if (s[x]) break;else s[x]=++tt;
		}
		int now=(n-i)%(tt-s[x]+1)+s[x];
		for (i=1;i<=m;i++) if (s[i]==now) break;
		printf("%lld",i);
	}
	else if (n<=1000000){
		for (i=1;i<=n;i++) {
			x=(((a*x)%m*x)%m+b*x%m+c)%m;
		}
		printf("%lld",x);
	}
	else {
		if (m==1) printf("0");else {
			zs=fast(2,n,m-1);
			ans2=fast(x0+b/2/a,zs,m);
			if (zs==0) zs=m-1;else zs=zs-1;
			ans1=fast(a,zs,m);
			ans1=ans1*ans2%m;
			ans1=(ans1+m-(b/2/a)%m)%m;
		}
		printf("%lld",ans1);
	}
	return 0;
}
