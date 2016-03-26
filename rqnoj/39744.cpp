#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 300007;
const int inf = (int)1e9 + (int)1e8;

struct Node{
	int num;
	long long v;
}tree[N * 50];

struct Dat{
	int x,y,m,p,r;
	long long dis;
}a[N];

int sx,sy,sp,sr,n,Q[N + 100],c[N + 100];

bool cmp(Dat x , Dat y)
{
	return x.dis < y.dis;
}

long long sqr(int x)
{
	return (long long)x * x;
}

void Init()
{
	scanf("%d%d%d%d%d" , &sx , &sy , &sp , &sr , &n);
	for (int i = 1 ; i <= n ; i ++)
	{
		int x , y , m , p , r;
		scanf("%d%d%d%d%d" , &x , &y , &m , &p , &r);
		a[i].x = x - sx;
		a[i].y = y - sy;
		a[i].m = m , a[i].p = p , a[i].r = r;
		a[i].dis = sqr(a[i].x) + sqr(a[i].y);
	}
	sx = sy = 0;
	a[0].x = a[0].y = a[0].m = 0;
	a[0].dis = 0 , a[0].p = sp , a[0].r = sr;
}

int Select(long long num)
{
	int l = 1 , r = n , ans = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[mid].dis <= num) ans = mid , l = mid + 1 ; else r = mid - 1;
	}
	return ans;
}

void Maketree(int x , int l , int r)
{
	if (l == r) {tree[x].v = a[l].m , tree[x].num = l , c[l] = x; return ;}
	int mid = (l + r) >> 1;
	Maketree(x * 2 , l , mid) , Maketree(x * 2 + 1 , mid + 1 , r);
	if (tree[x * 2].v > tree[x * 2 + 1].v)
		tree[x] = tree[x * 2 + 1] ; else tree[x] = tree[x * 2];
}

int Cha(int x , int L , int R , int l , int r)
{
	if (L == l && R == r) return tree[x].num;
	int mid = (L + R) >> 1;
	if (r <= mid) return Cha(x * 2 , L , mid , l , r);
	if (l > mid) return Cha(x * 2 + 1 , mid + 1 , R , l , r);
	int k1 , k2;
	k1 = Cha(x * 2 , L , mid , l , mid);
	k2 = Cha(x * 2 + 1 , mid + 1 , R , mid + 1 , r);

	return (a[k1].m < a[k2].m) ? k1 : k2;
}

void Up(int x)
{
	while (x != 1)
	{
		x >>= 1;
		tree[x] = (tree[x * 2].v < tree[x * 2 + 1].v) ? tree[x * 2] : tree[x * 2 + 1];
	}
}

void Preprocessing()
{
	sort(a + 1 , a + 1 + n , cmp);
	Maketree(1 , 1 , n);
}

void Work()
{
	Q[1] = 0;
	int l = 0 , r = 1;
	while (l < r)
	{
		int now = Q[++l];
		int R = Select(sqr(a[now].r));
		if (R <= 0) continue;
		int k = Cha(1 , 1 , n , 1 , R);
		while (k > 0 && a[k].m <= a[now].p)
		{
			Q[++r] = k;
			tree[c[k]].v = a[k].m = inf;
			Up(c[k]);
			k = Cha(1 , 1 , n , 1 , R);
		}
	}
	printf("%d" , r - 1);
}

int main()
{
	Init();
	Preprocessing();
	Work();
	
	return 0;
}
