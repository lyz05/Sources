#include<cstdio>
#include<iostream>
#define fo(i,x,y) for (int i=x;i<=y;++i)
using namespace std;

const int maxm=100000+10, maxn=maxm+100000+10, mod=7459;

struct node{
    int x,y,sa,cnt;
} a[maxn*3];

int n,m,b[maxn],q[maxm][4];
char str[10];

void mark(int v,int l,int r){
    a[v].cnt=r-l+1; a[v].x=a[v].y=a[v].sa=0;
    if (l==r) return;
    int md=(l+r)/2; mark(v*2,l,md); mark(v*2+1,md+1,r);
}

int place(int v,int l,int r,int x,int del){
    if (l==r){ a[v].cnt-=del; return l; }
    int ret,md=(l+r)/2;
    if (x<=a[v*2].cnt) ret=place(v*2,l,md,x,del);
    else ret=place(v*2+1,md+1,r,x-a[v*2].cnt,del);
    a[v].cnt-=del;
    return ret;
}

int calc(int v){
    return ((2*a[v].y*a[v].sa+a[v].sa*a[v].sa%mod*a[v].cnt)%mod+mod)%mod;
}

void down(int v){
    int l=v*2, r=v*2+1;
    if (a[l].cnt) a[l].sa=(a[l].sa+a[v].sa)%mod;
    if (a[r].cnt) a[r].sa=(a[r].sa+a[v].sa)%mod;
    a[v].sa=0;
}

void update(int v){
    int l=v*2, r=v*2+1;
    a[v].x=(a[l].x+a[r].x+calc(l)+calc(r))%mod;
    a[v].y=(a[l].y+a[r].y+a[l].sa*a[l].cnt+a[r].sa*a[r].cnt)%mod;
    a[v].cnt=a[l].cnt+a[r].cnt;
}

void maketree(int v,int l,int r,int st){
    a[v].sa=0;
    if (l==r){
        if (!a[v].cnt) return;
        a[v].x=b[st]*b[st]%mod;
        a[v].y=b[st]%mod;
        return;
    }
    int md=(l+r)/2;
    maketree(v*2,l,md,st);
    maketree(v*2+1,md+1,r,st+a[v*2].cnt);
    update(v);
}

void ins(int v,int l,int r,int p,int q){
    if (l==r){
        a[v].x=q*q%mod;
        a[v].y=q%mod;
        a[v].sa=0;
        ++a[v].cnt;
        return;
    }
    down(v);
    int md=(l+r)/2;
    if (p<=md) ins(v*2,l,md,p,q); else ins(v*2+1,md+1,r,p,q);
    update(v);
}

void add(int v,int l,int r,int x,int y,int z){
    if (l==x && r==y){
        if (a[v].cnt) a[v].sa=(a[v].sa+z)%mod;
        return;
    }
    down(v);
    int md=(l+r)/2;
    if (y<=md) add(v*2,l,md,x,y,z);
    else if (x>md) add(v*2+1,md+1,r,x,y,z);
    else {
        add(v*2,l,md,x,md,z);
        add(v*2+1,md+1,r,md+1,y,z);
    }
    update(v);
}

int query(int v,int l,int r,int x,int y){
    if (l==x && r==y) return (a[v].x+calc(v))%mod;
    down(v);
    int md=(l+r)/2, ret;
    if (y<=md) ret=query(v*2,l,md,x,y);
    else if (x>md) ret=query(v*2+1,md+1,r,x,y);
    else ret=(query(v*2,l,md,x,md)+query(v*2+1,md+1,r,md+1,y))%mod;
    update(v);
    return ret;
}

int main(){
    freopen("mission.in","r",stdin);
    freopen("mission.out","w",stdout);
    scanf("%d",&n);
    fo(i,1,n) scanf("%d",&b[i]);
    scanf("%d",&m);
    fo(i,1,m){
        scanf("%s%d%d",str,&q[i][1],&q[i][2]);
        if (str[0]=='I') q[i][0]=0, ++n;
        if (str[0]=='A'){ q[i][0]=1; scanf("%d",&q[i][3]); }
        if (str[0]=='Q') q[i][0]=2;
    }
    mark(1,1,n);
    for (int i=m;i;--i)
        if (q[i][0]) q[i][1]=place(1,1,n,q[i][1],0), q[i][2]=place(1,1,n,q[i][2],0);
        else q[i][1]=place(1,1,n,q[i][1],1);
    maketree(1,1,n,1);
    fo(i,1,m)
        if (q[i][0]==0) ins(1,1,n,q[i][1],q[i][2]);
        else if (q[i][0]==1) add(1,1,n,q[i][1],q[i][2],q[i][3]);
        else printf("%d\n",query(1,1,n,q[i][1],q[i][2]));
    return 0;
}
