#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXW = 200000+5,MAXL = MAXW,N = 100000+5;
struct node
{int x,y,z,id,next;} W[MAXW],L[MAXL],h[MAXW*2];

int n,w,l,tot,tot1;
int H[N],ans[2][N],e[N],vis[N],dep[N];
int fa[N][20],ma[N][20],id[N][20];
bool flag;

bool cmp(node A,node B)
{return A.z<B.z;}

int gf(int x)
{
	if (x==H[x]) return x;
	else return H[x] = gf(H[x]);
}

bool link(int x,int y)
{
	int i = gf(x),j = gf(y);
	if (i==j) return 0;
	else 
	{
		H[i] = j;
		return 1;
	}
}

void add(int x,int y,int z,int Id)
{
	tot1 ++;
	h[tot1].y = y;
	h[tot1].z = z;
	h[tot1].next = e[x];
	h[tot1].id = Id;
	e[x] = tot1;
}

void dfs(int x)	//OK
{
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y,z = h[i].z,Id = h[i].id;
		if (vis[y]) continue;
		vis[y] = 1;
		dep[y] = dep[x] + 1;
		fa[y][0] = x;
		ma[y][0] = z;
		id[y][0] = Id;
		dfs(y);
	}
}

void init() //OK
{
	for (int j=1;(1<<j)<=n;j ++)
		for (int i=1;i<=n;i ++)
		if (fa[i][j-1])
		{
			fa[i][j] = fa[fa[i][j-1]][j-1];
			if (fa[i][j])
			{
			ma[i][j] = max(ma[i][j-1],ma[fa[i][j-1]][j-1]);
			id[i][j] = (ma[i][j-1]>ma[fa[i][j-1]][j-1])?
				id[i][j-1]:id[fa[i][j-1]][j-1];
			}
		}
}

void prepar()
{
	flag = 0;tot = 0;
	memset(ans[1],0,sizeof ans[1]);
	for (int i=1;i<=n;i ++) H[i] = i;

	for (int j=1;j<=w;j ++)
	{
		if (link(W[j].x,W[j].y)) 
		{
			add(W[j].x,W[j].y,W[j].z,W[j].id);
			add(W[j].y,W[j].x,W[j].z,W[j].id);

			ans[1][0] += W[j].z;
			ans[1][++ tot] = W[j].id;
			if (tot==n-1)
			{
				flag = 1;
				break;
			}
		}
	}
	dep[1] = 1;vis[1] = 1;
	dfs(1);
	init();
}

void get(int x,int y,int &Id,int &val)
{
	int i,j;
	if (dep[x]<dep[y]) swap(x,y);
	for (i=0;(1<<i)<=dep[x];i ++);
	i --;

	for (j=i;j>=0;j --)
		if (dep[x]-(1<<j)>=dep[y])
		{
			Id = (val>ma[x][j])?Id:id[x][j];
			val = max(val,ma[x][j]);
			x = fa[x][j];
		}
	//dep ÏàÍ¬
	if (x==y) return;
	for (j=i;j>=0;j --)
	{
		if (fa[x][j] && fa[x][j]!=fa[y][j])
		{
			Id = (val>ma[x][j])?Id:id[x][j];
			val = max(val,ma[x][j]);
			x = fa[x][j];
			Id = (val>ma[y][j])?Id:id[y][j];
			val = max(val,ma[y][j]);
			y = fa[y][j];
		}
	}
	Id = (val>ma[x][0])?Id:id[x][0];
	val = max(val,ma[x][0]);
	Id = (val>ma[y][0])?Id:id[y][0];
	val = max(val,ma[y][0]);
}

void work()
{
	ans[0][0] = 1e9+7;
	sort(W+1,W+1+w,cmp);
	sort(L+1,L+1+l,cmp);
	prepar();
	if (!flag && tot==n-2)
	{
		for (int i=1;i<=l;i ++)
		{
			if (link(L[i].x,L[i].y))
			{
				ans[1][0] += L[i].z;
				ans[1][n-1] = L[i].id;
				break;
			}
		}
		memcpy(ans[0],ans[1],sizeof ans[1]);
	} else 
	{
		int tmp = 1e9+7,k = 0;
		for (int i=1;i<=l;i ++)
		{
			int id = 0,val = 0;
			get(L[i].x,L[i].y,id,val);
			if (tmp>ans[1][0]-val+L[i].z)
			{
				tmp = ans[1][0]-val+L[i].z;
				k = id;
				ans[1][n] = L[i].id;
			}
		}
		ans[0][0] = tmp;
		for (int i=1,j=1;i<=n-1;i ++,j ++)
		{
			if (ans[1][i]==k) j --;
			else ans[0][j] = ans[1][i];
		}
		ans[0][n-1] = ans[1][n];
	}
}

int main()	//OK
{
	freopen("telephone.in","r",stdin);
	//freopen("telephone.out","w",stdout);

	int x,y,z;
	scanf("%d%d%d",&n,&w,&l);
	for (int i=1;i<=w;i ++) 
	{
		scanf("%d%d%d",&x,&y,&z);
		W[i].x = x,W[i].y = y,W[i].z = z,W[i].id = i;
	}
	for (int i=1;i<=l;i ++)
	{
		scanf("%d%d%d",&x,&y,&z);
		L[i].x = x,L[i].y = y,L[i].z = z,L[i].id = i;
	}

	work();
	for (int i=0;i<=n-1;i ++) printf("%d\n",ans[0][i]);

	return 0;
}

