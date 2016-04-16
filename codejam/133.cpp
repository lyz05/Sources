#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mem(a,b) memset(a,b,sizeof(a));
using namespace std;

const int maxn=1005;

int n,fa[maxn],ans;

int tot,go[maxn],next[maxn],f1[maxn];
void ins(int x,int y)
{
	go[++tot]=y;
	next[tot]=f1[x];
	f1[x]=tot;
}

int dfn[maxn],low[maxn],z[maxn],z0,sum;
bool bz[maxn];
void Tarjan(int k)
{
	dfn[k]=low[k]=++sum;
	z[++z0]=k;
	bz[k]=1;
	if (!dfn[fa[k]])
	{
		Tarjan(fa[k]);
		low[k]=min(low[k],low[fa[k]]);
	} else if (bz[fa[k]]) low[k]=min(low[k],dfn[fa[k]]);
	if (dfn[k]==low[k])
	{
		int num=1;
		while (z[z0]!=k)
		{
			num++;
			bz[z[z0--]]=0;
		}
		ans=max(ans,num);
		bz[z[z0--]]=0;
	}
}

int dfs(int k,int s)
{
	int re=s;
	for(int p=f1[k]; p; p=next[p]) 
		if (go[p]!=fa[k]) re=max(re,dfs(go[p],s+1));
	return re;
}

int T;
int main()
{
	freopen("13.in","r",stdin);
	freopen("133.out","w",stdout);
	
	scanf("%d",&T);
	fo(Ti,1,T)
	{
		printf("Case #%d: ",Ti);
		
		tot=0; mem(f1,0); ans=0;
		
		scanf("%d",&n);
		fo(i,1,n)
		{
			scanf("%d",&fa[i]);
			ins(fa[i],i);
		}
		
		mem(dfn,0);
		fo(i,1,n) if (!dfn[i]) Tarjan(i);
		
		int ans1=0;
		fo(i,1,n) if (fa[fa[i]]==i) ans1+=dfs(i,1)+dfs(fa[i],1);
		
		printf("%d\n",max(ans,ans1/2));
	}
}

