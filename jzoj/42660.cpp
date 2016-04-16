#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define maxn 14
#define maxk 25
#define pr pair<double,double>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
using namespace std;

struct note{
	int r,cost;
}a[maxk];

int x[maxn],y[maxn],n,k,f[15000],sh[maxn],mi;

double sqr(double x){return x*x;}

double make(double x1,double y1,double x2,double y2){
	if (x1==x2) return 0;
	if (y2==y1) return 0;
	return (y2-y1)/(x2-x1);
}

pr get(int w1,int w2,double r,int up){
	double x1=x[w1],y1=y[w1],x2=x[w2],y2=y[w2];
	if (x1>x2){
		swap(x1,x2);
		swap(y1,y2);
	}
	double m1=(x1+x2)/2,m2=(y1+y2)/2;
	r=sqrt(sqr(r)-(sqr(m1-x1)+sqr(m2-y1)));
	double xl=make(x1,y1,x2,y2);
	if (xl==0) {
		if (x1==x2){
			pr ret;
			if (up==0) ret=mp(m1-r,m2);
			else ret=mp(m1+r,m2);
			return ret;
		}
		else {
			pr ret;
			if (up==0) ret=mp(m1,m2+r);
			else ret=mp(m1,m2-r);
			return ret;
		}
	}
	double nxl=(-1)/xl;
	double x=sqrt(r*r/(1+sqr(nxl)));
	pr ret;
	if (up==0) ret=mp(m1-x,m2-nxl*x);
	else ret=mp(m1+x,m2+nxl*x);
	return ret;
}

int main(){
	freopen("circle.in","r",stdin);
	//freopen("circle.out","w",stdout);
	scanf("%d%d",&n,&k);
	sh[0]=1;
	fo(i,1,n) sh[i]=sh[i-1]*2;
	fo(i,1,n) scanf("%d%d",&x[i],&y[i]);
	mi=100000000;
	fo(i,1,k){
		scanf("%d%d",&a[i].r,&a[i].cost);
		mi=min(mi,a[i].cost);
	}
	
	memset(f,63,sizeof(f));
	fo(i,1,n) f[sh[i-1]]=mi;
	fo(i,1,n-1)
		fo(j,i+1,n) 
			fo(co,1,k){
				if (sqr(x[i]-x[j])+sqr(y[i]-y[j])>4*sqr(a[co].r)) continue;
				fo(up,0,1){
					pr ct=get(i,j,a[co].r,up);
					int tmp=sh[i-1]|sh[j-1];
					fo(now,1,n)
						if (sqr((double)x[now]-ct.fi)+
					sqr(double(y[now])-ct.se)<=sqr(a[co].r))
							tmp=tmp|sh[now-1];
					f[tmp]=min(f[tmp],a[co].cost);
				}
			}
	fo(i,1,sh[n]-2)
		fo(j,1,i-1)
			f[i|j]=min(f[i|j],f[i]+f[j]);
	printf("%d",f[sh[n]-1]);
	return 0;
}

