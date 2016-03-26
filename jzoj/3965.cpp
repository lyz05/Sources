#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int M = int(3e6) + 5;
const int N = int(2e5) + 5;
int n , K;
int g[N] , x[N] , y[N] , what[N] , pos[N] , wh[N];
int tr[2*M*4] , add[2*M*4];
// -1e6 <= x-y <= 1e6
// 2*1e6 <= x-y+M <= 4*1e6
// 0 <= K <= 2*1e6
// 0<= x-y+M-K , x=y+M+K <= 6*1e6

bool cmd(int x,int y)
{
	if (pos[x] != pos[y]) return pos[x] < pos[y];
	return what[x] < what[y];
}

void Init()
{
	scanf("%d%d",&n,&K);
	int xx,yy;
	fo(i,1,n)
	{
		scanf("%d%d%d",&g[i*2],&xx,&yy);
		g[i*2-1] = g[i*2];
		x[i*2-1] = xx + yy; y[i*2-1] = xx - yy + M;
		pos[i*2-1] = x[i*2-1] + K;
		what[i*2-1] = 2;
		
		x[i*2] = xx + yy; y[i*2] = xx - yy + M;
		pos[i*2] = x[i*2] - K;
		what[i*2] = 1;
	}
	fo(i,1,n<<1) wh[i] = i;
	sort(wh+1,wh+1+2*n,cmd);
}

void down(int x)
{
	if (!add[x]) return;
	tr[x+x] += add[x];
	tr[x+x+1] += add[x];
	add[x+x] += add[x];
	add[x+x+1] += add[x];
	add[x] = 0;
}

void insert(int x,int l,int r,int p,int q,int v)
{
	if (l != r) down(x);
	if (l == p && r == q)
	{
		tr[x] += v;
		add[x] += v;
		return;
	}
	int mid = (l + r)>>1;
	if (q<=mid) insert(x+x,l,mid,p,q,v);else
	if (p>mid) insert(x+x+1,mid+1,r,p,q,v);else
	{
		insert(x+x,l,mid,p,mid,v);
		insert(x+x+1,mid+1,r,mid+1,q,v);
	}
	if (tr[x+x] > tr[x+x+1]) tr[x] = tr[x+x];else tr[x] = tr[x+x+1];
}

void Work()
{
	int i = 1 , ans = 0;
	while (i <= n*2)
	{
		int k = pos[wh[i]];
		while (i<=n*2 && pos[wh[i]] == k && what[wh[i]] == 1)
		insert(1,1,M*2,y[wh[i]] - K,y[wh[i]] + K,g[wh[i]]) , i++;
		if (ans < tr[1]) ans = tr[1];
		k = pos[wh[i]];
		while (i<=n*2 && pos[wh[i]] == k && what[wh[i]] == 2)
		insert(1,1,M<<1,y[wh[i]] - K,y[wh[i]] + K,-g[wh[i]]) , i++;
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("3965.in","r",stdin);
	Init();
	Work();
	
	return 0;
}
