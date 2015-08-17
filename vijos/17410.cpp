#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#define MAXN 1002
#define MAXM 10002
using namespace std;
int n,m,K,d[MAXN];
struct ren{int t,a,b;} r[MAXM];
int arv[MAXN],sum[MAXN],last[MAXN];
int nx[MAXN],ans,tot;
//------------------------------------------------------------
void init()
{
	scanf("%d%d%d",&n,&m,&K);
	int i;
	for(i=1;i<n;i++) scanf("%d",&d[i]);
	for(i=1;i<=m;i++)
	   {scanf("%d%d%d",&r[i].t,&r[i].a,&r[i].b);
	    last[r[i].a]=max(last[r[i].a],r[i].t);
	    sum[r[i].b]++;
	   }
	for(i=2;i<=n;i++)
	   {arv[i]=max(arv[i-1],last[i-1])+d[i-1];
	    sum[i]+=sum[i-1];
	   }
	nx[n]=n; nx[n-1]=n;
	for(i=n-2;i>=1;i--)
	   {if(arv[i+1]>last[i+1]) nx[i]=nx[i+1];
	    else nx[i]=i+1;
	   }
	for(i=1;i<=m;i++) ans+=arv[r[i].b]-r[i].t;
}
void work()
{
	int i,maxs=0,l,r;
	for(i=1;i<=n-1;i++)
	   {if(maxs<sum[nx[i]]-sum[i]&&d[i]>0)
	       {maxs=sum[nx[i]]-sum[i]; l=i; r=nx[i];}
	   }
	tot+=maxs;
	d[l]--;
	if(r==n) r=n-1;
	for(i=l+1;i<=r;i++) arv[i]=max(arv[i-1],last[i-1])+d[i-1];
	for(i=r;i>=l;i--)
	   {if(arv[i+1]>last[i+1]) nx[i]=nx[i+1];
	    else nx[i]=i+1;
	   }
}
int main()
{
	freopen("1741.in","r",stdin);

	init();
	while(K--) work();
	printf("%d\n",ans-tot);
	return 0;
}
