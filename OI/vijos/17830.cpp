#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mid (L+R>>1)
using namespace std;

typedef long long LL;
const int N=50000+19;
typedef int one[N];
struct Edge {int y,z,nxt;} E[N*2];
struct Army
{
    int B;LL D;
    bool operator < (const Army& Ar) const {return D<Ar.D;}
} A[N],C[N];
one Last,W,vis,Bel,Q;
int Fa[N][16];LL D[N][16];
int n,m,cnt,x,y,z,tot,Time,An,ID,Cn,cur;
LL L,R,res;

int IN()
{
    int c,x;
    while (!isdigit(c=getchar()));x=c-'0';
    while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

void Link(int x,int y,int z)
{
    E[cnt]=(Edge){y,z,Last[x]};Last[x]=cnt++;
    E[cnt]=(Edge){x,z,Last[y]};Last[y]=cnt++;
}
void DFS(int x,int Anc)
{
    Bel[x]=Anc;Q[++ID]=x;
    for (int i=Last[x];~i;i=E[i].nxt)
        if (E[i].y!=Fa[x][0]) Fa[E[i].y][0]=x,D[E[i].y][0]=E[i].z,DFS(E[i].y,Anc);
}
bool Check(LL T)
{
    An=Cn=0,cur=1,Time++;
    For(i,1,m+1)
    {
        int x=W[i];LL y=T;
        for (int j=15;~j;j--) if (y>=D[x][j]) y-=D[x][j],x=Fa[x][j];
        if (x==0) A[++An]=(Army){Bel[W[i]],y};else vis[x]=Time;
    }
    for (int x=ID;x;x--)
        if (vis[Q[x]]!=Time&&~Last[Q[x]])
        {
            vis[Q[x]]=Time;
            for (int i=Last[Q[x]];~i;i=E[i].nxt)
                if (vis[E[i].y]!=Time) vis[Q[x]]=Time-1;
        }
    for (int i=Last[1];~i;i=E[i].nxt)
        if (vis[E[i].y]!=Time) C[++Cn]=(Army){E[i].y,D[E[i].y][0]};

    sort(A+1,A+An+1);
    sort(C+1,C+Cn+1);

    while (cur<=Cn&&vis[C[cur].B]==Time) cur++;
    For(i,1,An+1)
    {
        if (vis[A[i].B]!=Time) vis[A[i].B]=Time;else
            if (cur<=n&&A[i].D>=C[cur].D) vis[C[cur++].B]=Time;
        while (cur<=Cn&&vis[C[cur].B]==Time) cur++;
    }
    return cur>Cn;
}

int main()
{
	freopen("1783.in","r",stdin);
    memset(Last,-1,sizeof(Last));
    n=IN();
    For(i,1,n) x=IN(),y=IN(),z=IN(),Link(x,y,z);
    m=IN();
    For(i,1,m+1) W[i]=IN();

    Q[++ID]=1;
    for (int i=Last[1];~i;i=E[i].nxt)
    {
        Fa[E[i].y][0]=1,D[E[i].y][0]=E[i].z;
        DFS(E[i].y,E[i].y),tot++;
    }
    if (m<tot) return puts("-1"),0;

    For(i,1,16) for (x=1;x<=n;x++) Fa[x][i]=Fa[Fa[x][i-1]][i-1],D[x][i]=D[x][i-1]+D[Fa[x][i-1]][i-1];

    L=0,R=1LL<<60;
    while (L<=R) if (Check(Mid)) res=Mid,R=Mid-1;else L=Mid+1;
    printf("%lld\n",res);
}
