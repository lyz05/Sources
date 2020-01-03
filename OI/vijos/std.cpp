#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#define inf 100000000000000ll
#define maxn 250000
#define maxm 500+100
#define eps 1e-10
#define ll long long
#define pa pair<int,int>
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,a[2*maxn],b[2*maxn],c[2*maxn];
ll ti[maxn];
struct seg{int k,l,r;ll mi,tag;}t[8*maxn];
inline void build(int k,int l,int r)
{
    t[k].l=l;t[k].r=r;int mid=(l+r)>>1;
    t[k].mi=inf;t[k].tag=inf;
    if(l==r)return;
    build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
inline void update(int k,ll z)
{
    t[k].tag=min(t[k].tag,z);
    t[k].mi=min(t[k].mi,z);
}
inline void pushdown(int k)
{
    if(t[k].tag==inf)return;
    update(k<<1,t[k].tag);
    update(k<<1|1,t[k].tag);
    t[k].tag=inf;
}
inline void pushup(int k)
{
    t[k].mi=min(t[k<<1].mi,t[k<<1|1].mi);
}
inline void change(int k,int x,int y,ll z)
{
    int l=t[k].l,r=t[k].r,mid=(l+r)>>1;
    if(l==x&&r==y){update(k,z);return;}
    pushdown(k);
    if(y<=mid)change(k<<1,x,y,z);
    else if(x>mid)change(k<<1|1,x,y,z);
    else change(k<<1,x,mid,z),change(k<<1|1,mid+1,y,z);
    pushup(k);
}
inline ll query(int k,int x)
{
    int l=t[k].l,r=t[k].r,mid=(l+r)>>1;
    if(l==r)return t[k].mi;
    pushdown(k);
    if(x<=mid)return query(k<<1,x);else return query(k<<1|1,x);
}
inline bool cmp1(int x,int y){return a[x]<a[y];}
inline bool cmp2(int x,int y){return b[x]>b[y];}
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("s.out","w",stdout);
    int cs=read(),mm=0;
    while(cs--)
    {
        n=read();m=read();
        for1(i,n)a[i]=read(),a[n+i]=read(),ti[i]=read();a[2*n+1]=m;a[2*n+2]=1;
        for1(i,2*n+2)c[i]=i;
        sort(c+1,c+2*n+3,cmp1);
        int tot=0;
        for1(i,2*n+2)
        {
            if(i==1||a[c[i]]!=a[c[i-1]])tot++;
            b[c[i]]=tot;
        }
        for1(i,n)c[i]=i;
        sort(c+1,c+n+1,cmp2);
        build(1,1,tot);
        change(1,b[2*n+1],tot,0);
        for1(i,n)
        {
            ll x=query(1,b[c[i]]);if(x==inf)continue;
            if(b[c[i]]>b[n+c[i]])change(1,b[n+c[i]],b[c[i]]-1,x+ti[c[i]]);
        }
        ll ans=query(1,b[2*n+2]);
        printf("Case #%d: ",++mm);
        if(ans==inf)printf("-1\n");else printf("%lld\n",ans);
    }
    return 0;
}

