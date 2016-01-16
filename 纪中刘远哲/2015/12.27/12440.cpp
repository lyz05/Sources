#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,m,tot,cnt;
int x[1005],y[1005],fa[1005];
double ans;
struct edge{int x,y;double v;}e[1000005];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline ll sqr(int x){return (ll)x*x;}
inline double dis(int a,int b)
{return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]));}
inline bool cmp(edge a,edge b)
{return a.v<b.v;}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	    x[i]=read(),y[i]=read(),fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int p=find(read()),q=find(read());
		fa[p]=q;
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	e[++cnt].x=i;e[cnt].y=j;
		    e[cnt].v=dis(i,j);
	    }
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int p=find(e[i].x),q=find(e[i].y);
		if(p!=q)
		{
			fa[p]=q;
			ans+=e[i].v;
			tot++;if(tot==n-1)break;
		}
	}
	printf("%.2lf",ans);
	return 0;
}
