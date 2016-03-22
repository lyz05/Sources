#include<cstdio>
#include<cstring>
#include<algorithm>
#define FOR(a,b,c) for(int a=(b);a<=(c);a++)
using namespace std;

const int N = 200+10;
struct node {
    int a; double p;
    bool operator <(const node& rhs) const {
        return a>rhs.a;
    }
}ns[N];

double f[N][N][N];
int n,K,L;

int main() {
	freopen("2.in","r",stdin);
    scanf("%d%d%d",&n,&L,&K);
    FOR(i,1,n) {
        scanf("%lf",&ns[i].p);
        ns[i].p/=100;
    }
    FOR(i,1,n) scanf("%d",&ns[i].a);
    sort(ns+1,ns+n+1);
    f[0][0][min(K,n)]=1;
    FOR(i,0,n-1) FOR(j,0,i) FOR(k,0,n)
    {
        f[i+1][j][k] += f[i][j][k]*(1-ns[i+1].p);
        int t=k+ns[i+1].a;
        t=min(t,n);
        if(t<0) continue;
        f[i+1][j+1][t] += f[i][j][k]*ns[i+1].p;
    }
    double ans=0;
    FOR(j,L,n) FOR(k,0,n)
        ans += f[n][j][k];
    printf("%.6lf",ans);
    return 0;
}
