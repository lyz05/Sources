#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

const int N = 14,M = N*(N-1)/2,Mo = 3204637,Mot = 1871377;
struct node
{
	int a[N];
	node(){memset(a,0,sizeof a);}
} st,en;
struct node1
{
	int x,y;
} E[M];

typedef long long LL;
//map <LL,int> vis;
//map <LL,int> kk;
queue <LL> buf[2];
//queue <int> step[2];
int n,m,ans,tot;
LL Hash[Mo];
int vis[Mo],kk[Mo];

LL calc(node &x)
{
	LL ret = 0;
	for (int i=1;i<=n;i ++)
		ret = ret*13+x.a[i];
	return ret;
}

int getpos(LL st)
{
	int pos = st % Mo;
	while (Hash[pos] != -1 && Hash[pos] != st) pos = (pos + 1) % Mo;
	Hash[pos] = st;
	return pos;
}

void get(LL st,node &b)
{
	for (int i = n ; i ; i --)
	{
		b.a[i] = st % 13;
		st /= 13;
	}
}

int bfs(int kind)
{
	int ste = 0;
	if (!buf[kind].empty()) ste = vis[getpos(buf[kind].front())];
	while (!buf[kind].empty())
	{
		node now;
		LL ha = buf[kind].front();
		get(ha,now);
		if (vis[getpos(ha)]!=ste) return 0;
		buf[kind].pop();//step[kind].pop();
		for (int i=1;i<=tot;i ++)
		{
			swap(now.a[E[i].x],now.a[E[i].y]);
			ha = calc(now);
			if (!vis[getpos(ha)])
			{
				vis[getpos(ha)] = ste+1;
				kk[getpos(ha)] = kind;
				//step.push(ste+1);
				buf[kind].push(calc(now));
				//if (calc(now)==calc(en)) return ste+1;
			} else 
			{
				if (kk[getpos(ha)]==(kind^1)) 
				{
					ans = ste+vis[getpos(ha)]-1;
					return 1;//?
				}
			}
			swap(now.a[E[i].x],now.a[E[i].y]);
		}
		
	}
	
	return 0;
}

void work()
{
	LL sta = calc(st),end = calc(en);
	if (sta==end) {ans = 0;return;}
	vis[getpos(sta)] = 1;vis[getpos(end)] = 1;
	kk[getpos(sta)] = 0,kk[getpos(end)] = 1;
	buf[0].push(sta);buf[1].push(end);
	//step[0].push(0);step[1].push(0);
	
	bool flag = 0;
	for (int p=0;1;p^=1)
	{
		flag = bfs(p);
		if (flag) return;
	}
}

int main()
{
	freopen("1444.in","r",stdin);
	//freopen(".out","w",stdout);
	
	memset(Hash , 255 , sizeof Hash);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) scanf("%d",&st.a[i]),en.a[i] = i;
	for (int i=1;i<=m;i ++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==y) continue;
		E[++ tot].x = x;E[tot].y = y;
	}
	work();
	printf("%d\n",ans);
	return 0;
	
}
