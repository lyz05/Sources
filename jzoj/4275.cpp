#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int MM = 15000000,N = 300000+5, P = 1000000000;
struct node
{
	int l,r;
	LL num,sum;
} h[MM];

char s[10];
int tot,n,m,t,e[N];
LL p;

void modify(int x,int l,int r,int id,int dt)
{
	if (!x) return;
	h[x].num += dt;h[x].sum += dt*id;
	if (l==r) return;
	int mid = (l+r)>>1;
	if (id<=mid) 
	{
		if (!h[x].l) h[x].l=++ tot;
		modify(h[x].l,l,mid,id,dt);
	}
	else 
	{
		if (!h[x].r) h[x].r=++ tot;
		modify(h[x].r,mid+1,r,id,dt);
	}
}

int qrynum(int x,int l,int r,int id)
{
	if (!x) return 0;
	if (l==r) return h[x].num;
	int mid = (l+r)>>1;
	if (id<=mid) 
		return (h[x].r?h[h[x].r].num:0)+qrynum(h[x].l,l,mid,id);
	else	return qrynum(h[x].r,mid+1,r,id);
}

LL qrysum(int x,int l,int r,int id)
{
	if (!x) return 0;
	if (h[x].num<id) return h[x].sum;
	if (l==r) return 1ll*l*id;
	int mid = (l+r)>>1,rs = h[x].r?h[h[x].r].num:0;
	if (rs<id) 
		return (h[x].r?h[h[x].r].sum:0)+qrysum(h[x].l,l,mid,id-rs);
	else	return qrysum(h[x].r,mid+1,r,id);
}
int qrykth(int x,int l,int r,int k)
{
	if (!x) return 0;
	if (h[x].num<k) return 0;
	if (l==r) return l;
	int mid = (l+r)>>1, rs = h[x].r?h[h[x].r].num:0;
	if (rs>=k) 
		return qrykth(h[x].r,mid+1,r,k);
	else	return qrykth(h[x].l,l,mid,k-rs);
}

int main()
{
	freopen("grimoire.in","r",stdin);
	freopen("grimoire.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i ++) 
	{
		e[i] = i+1;
	}
	tot = n;
	for (int i=1;i<=m;i ++)
	{
		scanf("%s%d%lld",s,&t,&p);
		if (s[0]=='B') 
		{
			modify(e[t],1,P,p,1);
			if (qrynum(e[t],1,P,p)<=t)
			{
				int k = qrykth(e[t],1,P,t+1);
				if (k) modify(e[0],1,P,k,-1);
				modify(e[0],1,P,p,1);
			}
		} else 
		{
			if (qrynum(e[t],1,P,p)<=t)
			{
				int k = qrykth(e[t],1,P,t+1);
				if (k) modify(e[0],1,P,k,1);
				modify(e[0],1,P,p,-1);
			}
			modify(e[t],1,P,p,-1);
		}
		printf("%lld\n",qrysum(e[0],1,P,n));
	}
}
