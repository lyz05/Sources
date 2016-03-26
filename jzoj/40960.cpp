#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=100000+2,M=1000000+1,mo=1000;

struct node{
	int y,next,id;
	bool v,re;
} h[2*M];


int e[N],tot,n,m,q,bj,f[N],id[N],cnt,top;
int stack[N],dfn[N],low[N],sum[N],index;
bool v[N];

void add(int x,int y,int z,int re)
{
	tot++;
	h[tot].y=y;
	h[tot].next=e[x];
	h[tot].id=z;
	h[tot].re=re;
	e[x]=tot;
}

int dfs(int x)
{
	int i=e[x],d=1;
	while (i!=0)
	{
		if (!v[h[i].y])
		{
			v[h[i].y]=true;
			d+=dfs(h[i].y);
		}
		i=h[i].next;
	}
	sum[x]=d;
	return d;
}

int work()
{
	memset(v,0,sizeof v);
	int ans=0;
	for (int i=0;i<n;i++)
	{
		if (!v[i]) {
			v[i]=true;
			int tmp=dfs(i);
			ans+=tmp*(n-tmp);
		}
		//ans%=mo;
	}
	return (ans/2)%mo;
}


void tarjan(int cur)
{
	int next;
	dfn[cur]=low[cur]=++index;
	stack[++top]=cur;
	int i=e[cur];
	while (i!=0)
	{
		next=h[i].y;
		if (!v[next])
		{
			v[next]=true;
			tarjan(next);
			low[cur]=min(low[cur],low[next]);
			if (low[next]>=dfn[cur])
			{
				cnt++;
				do
				{
					next=stack[top--];
					//if (id[next]!=0) sum[id[next]]--;
					id[next]=cnt;
					//sum[cnt]++;
				}while (next!=cur);
				top ++;

			}
		} else low[cur]=min(low[cur],dfn[next]);
		i=h[i].next;
	}
}

void dfs1(int x,int col,int root)
{
	int i=e[x];
	while (i!=0)
	{
		if (!h[i].v)
		{
			v[h[i].y]=true;
			h[i].v=true;
			if (id[h[i].y]!=col && h[i].re==0)
			{
				f[h[i].id]=sum[h[i].y]*(sum[root]-sum[h[i].y]);
				f[h[i].id]%=mo;
			}
			dfs1(h[i].y,id[h[i].y],root);
		}
		i=h[i].next;
	}
}

void work1(int x)
{
	memset(v,0,sizeof v);
	if (x==0){
	memset(dfn,0,sizeof dfn);
	}
	for (int i=0;i<n;i++)
	{
		if (!v[i])
		{
			v[i]=true;
			if (x==0) tarjan(i); else dfs1(i,id[i],i);
		}
	}
}



int main()
{
	freopen("4096.in","r",stdin);
	tot=0;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,i,0);
		add(v,u,i,1);
	}
	f[n]=work();
	work1(0);
	work1(1);
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&bj);
		int ans=(f[bj]+f[n])%mo;
		printf("%d\n",ans);
	}
}
