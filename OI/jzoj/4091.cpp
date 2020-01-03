#include <cstdio>
#include <cstring>
#define N 100000

struct node{
	int next,y,st;
}h[12*N];

int a[N],e[N],s[6*N],n,m,tot;
bool p1[N],p2[N],flag;

void add(int x,int y,int st)
{
	x=x%n;
	y=y%n;
	tot++;
	h[tot].y=y;
	h[tot].next=e[x];
	h[tot].st=st;
	e[x]=tot;
}

void bfs1(int x,int st)
{
	int i;
	memset(p1,0,sizeof p1);
	p1[x]=true;
	int l=1,r=1;
	s[l]=x;
	while (l<=r) {
		i=e[s[l]];
		while (i!=0)
		{
			if ((h[i].st==st) && (!p1[h[i].y])){
				p1[h[i].y]=1;
				r++;
				s[r]=h[i].y;
			}
			i=h[i].next;
		}
		l++;
	}

}
void bfs2(int x,int st)
{
	int i;
	memset(p2,0,sizeof p2);
	p2[x]=true;
	int l=1,r=1;
	s[l]=x;
	while (l<=r) {
		i=e[s[l]];
		while (i!=0)
		{
			if ((h[i].st==st) && (!p2[h[i].y])){
				p2[h[i].y]=1;
				r++;
				s[r]=h[i].y;
			}
			i=h[i].next;
		}
		l++;
	}

}
int main()
{
	freopen("4091.in","r",stdin);
	
	int t;
	scanf("%d\n",&t);
	for (;t>0;t--)
	{
		memset(a,255,sizeof a);
		memset(e,0,sizeof e);
		tot=0;

		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		for (int i=0;i<=n-2;i++)
		{
			for (int j=i+1;j<=i+6;j++)
			{
				if (a[j]!=-1){
					add(i,a[j],1);
					add(a[j],i,2);
				} else {
					add(i,j,1);
					add(j,i,2);
				}
			}
		}
		bfs1(0,1);
		bfs2(n-1,2);
		flag=false;
		for (int i=0;i<=n-1;i++)
			if (p1[i] && (!p2[i])) {
				flag=true;
				break;
			}
		if (flag) printf("YES\n");else printf("NO\n");

	}
}
