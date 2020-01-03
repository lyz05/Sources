#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 200005,M = 200*N;//M = 4*8*N*2;
struct node
{int x,id1,id2;} s[N];
struct node1{
	int y,z;
}t[4*N];
struct node2{
	int l,r,sum;
}tree[M];

int a[N][7];
int n[4],tot;

bool cmp(node A,node B){
	return A.x<B.x;
}


void prepare(int A,int B,int C)
{
	int tot=0;
	for (int i=1;i<=n[0];i ++) {
		s[++tot].x = a[i][B];
		s[tot].id1 = i;
		s[tot].id2 = B;
		s[++tot].x = a[i][C];
		s[tot].id1 = i;
		s[tot].id2 = C;
	}
	sort(s+1,s+tot+1,cmp);
	int last=-1e9+7,tmp=0;
	for (int i=1;i<=tot;i ++) {
		if (last!=s[i].x) tmp ++;
		a[s[i].id1][s[i].id2]=tmp;
		last = s[i].x;
	}
	n[A]=tmp;
}

void add(int typ,int &v,int l,int r,int x)
{
	if (v==0) v = ++ tot;
	if (l==r) 
	{
		tree[v].sum ++;
		return;
	}
	int mid = (l+r)>>1;
	if (x<=mid) add(typ,tree[v].l,l,mid,x);
	else add(typ,tree[v].r,mid+1,r,x);
	tree[v].sum = tree[tree[v].l].sum + tree[tree[v].r].sum;
}


void add1(int v,int l,int r,int x,int y,int z)
{
	add(2,t[v].y,1,n[2],y);
	add(3,t[v].z,1,n[3],z);
	if (l==r) return;
	int mid = (l+r)>>1;
	if (x<=mid) add1(v+v,l,mid,x,y,z);
	else add1(v+v+1,mid+1,r,x,y,z);
}

int ask(int v,int l,int r,int x,int y){
	if (v==0) return 0;
	if (l==x && r==y) return tree[v].sum;
	int mid=(l+r) >> 1;
	if (y<=mid) return ask(tree[v].l,l,mid,x,y);
	else if (x>mid) return ask(tree[v].r,mid+1,r,x,y);
	else return ask(tree[v].l,l,mid,x,mid)+ask(tree[v].r,mid+1,r,mid+1,y);
}

int ask1y(int v,int l,int r,int x1,int x2,int y1,int y2){
	if (l==x1 && r==x2) {
		return ask(t[v].y,1,n[2],y1,y2);
	}
	int mid=(l+r) >> 1;
	if (x2<=mid) return ask1y(v+v,l,mid,x1,x2,y1,y2);
	else if (x1>mid) return ask1y(v+v+1,mid+1,r,x1,x2,y1,y2);
	else return
	ask1y(v+v,l,mid,x1,mid,y1,y2)+ask1y(v+v+1,mid+1,r,mid+1,x2,y1,y2);
}

int ask1z(int v,int l,int r,int x1,int x2,int z1,int z2){
	if (l==x1 && r==x2) {
		return ask(t[v].z,1,n[3],z1,z2);
	}
	int mid=(l+r) >> 1;
	if (x2<=mid) return ask1z(v+v,l,mid,x1,x2,z1,z2);
	else if (x1>mid) return ask1z(v+v+1,mid+1,r,x1,x2,z1,z2);
	else return
	ask1z(v+v,l,mid,x1,mid,z1,z2)+ask1z(v+v+1,mid+1,r,mid+1,x2,z1,z2);
}


int main()
{
	freopen("4419.in","r",stdin);
	//freopen("4419.out","w",stdout);

	scanf("%d",&n[0]);
	for (int i=1;i<=n[0];i ++)
	{
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][6]);
		a[i][2] = a[i][0]+a[i][1];
		for (int j=0;j<3;j ++) a[i][j+3] = a[i][j] + a[i][6];
		//if (a[i][6]) a[i][6] = 1;
	}
	prepare(1,0,3);
	prepare(2,1,4);
	prepare(3,2,5);
	for (int i=1;i<=n[0];i ++)
	{
		if (!a[i][6])
			add1(1,1,n[1],a[i][0],a[i][1],a[i][2]);
		else
		{
			int ans = 0;
			ans = ask1y(1,1,n[1],a[i][0],a[i][3],a[i][1],n[2]);
			if (a[i][5]<n[3]) ans -= ask1z(1,1,n[1],a[i][0],a[i][3],a[i][5]+1,n[3]);
			printf("%d\n",ans);
		}
	}

	return 0;
}
