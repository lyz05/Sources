#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
struct node{
	unsigned int a[7];
};
node merge(node a,node b)
{
	node re;
	memset(re.a,0,sizeof(re.a));
	fo(i,0,6)
		fo(j,0,i)
		re.a[i]=(re.a[i]+a.a[j]*b.a[i-j]);
	return re;
}
const int N=1e5+7;
struct pol{
	int x,y;
} a[N];
int n,k;
bool cmp(const pol &a,const pol &b)
{
	return a.x<b.x;
}
int getleft(int x)
{
	int l=1,r=n,ans=n+1;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (x<=a[mid].x) ans=mid,r=mid-1; else
		l=mid+1;
	}
	return ans;
}
int getright(int x)
{
	int l=1,r=n,ans=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (a[mid].x<=x) ans=mid,l=mid+1; else
		r=mid-1;
	}
	return ans;
}
node f[N*3];
int eld[N*3];
void build(int l,int r,int v)
{
	if (l==r)
	{
		eld[v]=l;
		f[v].a[0]=1;
		f[v].a[1]=a[l].y;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,v+v);
	build(mid+1,r,v+v+1);
	if (a[eld[v+v]].y<a[eld[v+v+1]].y) eld[v]=eld[v+v]; else
	eld[v]=eld[v+v+1];
	f[v]=merge(f[v+v],f[v+v+1]);
}
int get_wz(int l,int r,int v,int x,int y)
{
	if (l==x && r==y) return eld[v];
	int mid=(l+r)>>1;
	if (y<=mid) return get_wz(l,mid,v+v,x,y); else
	if (x>mid) return get_wz(mid+1,r,v+v+1,x,y); else
	{
		int x1=get_wz(l,mid,v+v,x,mid),x2=get_wz(mid+1,r,v+v+1,mid+1,y);
		if (a[x1].y<a[x2].y) return x1; else return x2;
	}
}
node get(int l,int r,int v,int x,int y)
{
	if (l==x && r==y) return f[v];
	int mid=(l+r)>>1;
	if (y<=mid) return get(l,mid,v+v,x,y); else
	if (x>mid) return get(mid+1,r,v+v+1,x,y); else
	return merge(get(l,mid,v+v,x,mid),get(mid+1,r,v+v+1,mid+1,y));
}
int main()
{
	freopen("42370.in","r",stdin);
	int q;
	scanf("%d%d",&n,&q);
	fo(i,1,n) scanf("%d",&a[i].x);
	fo(i,1,n) scanf("%d",&a[i].y);
	sort(a+1,a+1+n,cmp);
	build(1,n,1);
	fo(i,1,q)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		l=getleft(l);
		r=getright(r);
		if (l>=r) printf("0\n"); else
		{
			int bz=get_wz(1,n,1,l,r);	//
			node ans;
			if (bz==l) ans=get(1,n,1,l+1,r); else
			if (bz==r) ans=get(1,n,1,l,r-1); else
			ans=merge(get(1,n,1,l,bz-1),get(1,n,1,bz+1,r));
			fo(i,1,k) ans.a[k]=(ans.a[k]*((unsigned int)i));
			cout<<ans.a[k]<<'\n';
		}
	}
	return 0;
}
