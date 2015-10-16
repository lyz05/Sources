#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
#define fi first
#define se second
using namespace std;

const int N = 125, mo = 1e9+7;

typedef pair<int,int> P;
typedef long long LL;

struct node
{
	int s[2],self;
	LL c,d,len;
} T[N];

LL size[N];
int Dis[N][N][N],All[N][N];
P Refer[N][N];
int Edge[N][N],tot[N],n;

int mark(int x,LL y)
{
	Edge[x][++ tot[x]] = y;
	int p = tot[x];
	if (x == 1) return tot[x];
	if (y > size[T[x].s[0]])
		Refer[x][p] = P(1,mark(T[x].s[1],y - size[T[x].s[0]]));
	else 
		Refer[x][p] = P(0,mark(T[x].s[0],y));
	return p;
}

void work()
{
	scanf("%d",&n);
	n ++;
	memset(tot,0,sizeof tot);
	size[1] = 1;
	for (int i=2;i<=n;i++)
	{
		scanf("%d%d%lld%lld%lld", &T[i].s[0], &T[i].s[1], &T[i].c, &T[i].d, &T[i].len);
		T[i].s[0] ++,T[i].s[1] ++,T[i].c ++,T[i].d ++;
		size[i] = size[T[i].s[0]] + size[T[i].s[1]];
		T[i].c = mark(T[i].s[0],T[i].c);
		T[i].d = mark(T[i].s[1],T[i].d);
	}
	for (int i=1;i<=n;i++) size[i] %= mo;
	for (int i=2;i<=n;i ++)
	{
		int l = T[i].s[0], r = T[i].s[1], len = T[i].len;
		for (int j=1;j<=tot[i];j++)
		{
			int b = Refer[i][j].fi,c = Refer[i][j].se;
			int m = (!b) ? T[i].c : T[i].d;
			for (int p=1;p<=tot[i];p ++)
			{
				int b1 = Refer[i][p].fi, c1 = Refer[i][p].se;
				int m1 = (!b1) ? T[i].c : T[i].d;
				if (b == b1) 
					Dis[i][j][p] = Dis[T[i].s[b]][c][c1];
				else	Dis[i][j][p] = ((Dis[T[i].s[b]][m][c] + Dis[T[i].s[b1]][m1][c1] % mo) % mo + len) % mo;
			}
		}
		for (int j=1;j<=tot[i];j++)
		{
			int b = Refer[i][j].fi;
			int dis = Dis[T[i].s[b]][(!b) ? T[i].c : T[i].d][Refer[i][j].se];
			All[i][j] = All[T[i].s[b]][Refer[i][j].se];
			All[i][j] = (All[i][j] + (All[T[i].s[!b]][b ? T[i].c : T[i].d] + size[T[i].s[!b]]*1ll*(len+dis)%mo)%mo)%mo;
		}
		T[i].self = (All[l][T[i].c] * 1ll * size[r] % mo + All[r][T[i].d] * 1ll * size[l] % mo) % mo;
		T[i].self = (T[i].self + 1ll * len * size[l] % mo * size[r] % mo) % mo;
		T[i].self = ((T[i].self + T[l].self) % mo + T[r].self) % mo;
		printf("%d\n",T[i].self);
	}
}

int main()
{
	freopen("4211.in","r",stdin);
		
	int T;
	scanf("%d",&T);
	while (T --) work();
	return 0;
}
