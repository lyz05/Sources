#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 250
#define P 45989
using namespace std;
int n,m,t,A,B;
int top=1,size;
int ans;
struct edge
{
    int from,to,num;
    edge *next;
}e[MAXN<<1],*prev[MAXN];
void insert(int u,int v)
{
    e[++top].to=v;e[top].next=prev[u];prev[u]=&e[top];e[top].num=top;e[top].from=u;
}
struct matrix
{
    int a[MAXN][MAXN];
    matrix()
    {
        memset(a,0,sizeof(a));
    }
    friend matrix operator *(matrix A,matrix B)
    {
        matrix ret;
        for (int i=1;i<=size;i++)
            for (int j=1;j<=size;j++)
                for (int k=1;k<=size;k++)
                    ret.a[i][j]=(ret.a[i][j]+A.a[i][k]*B.a[k][j])%P;
        return ret;
    }
    friend matrix operator ^(matrix x,int k)
    {
        matrix ret;
        for (int i=1;i<=size;i++)   ret.a[i][i]=1;
        for (int i=k;i;i>>=1,x=x*x)
            if (i&1)    ret=ret*x;
        return ret;
    }
}st,tmp,f;
int main()
{
	freopen("1088.in","r",stdin);
    scanf("%d%d%d%d%d",&n,&m,&t,&A,&B);
    for (int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v);insert(v,u);
    }
    size=top;
    for (edge *i=prev[A];i;i=i->next)   st.a[1][i->num]++;
    for (int i=2;i<=top;i++)
        for (int j=2;j<=top;j++)
            if (e[i].to==e[j].from&&i!=(j^1))   tmp.a[i][j]++;
    f=(tmp^(t-1));
    st=st*f;
    for (edge *i=prev[B];i;i=i->next)   ans+=st.a[1][i->num^1];
    ans%=P;
    printf("%d\n",ans);
}
