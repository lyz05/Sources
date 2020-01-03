#include<cstdio>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int N = 105;
int n , m;
int a[N][N] , sum[N][N];
char s[N];

void Init()
{
	scanf("%d%d",&n,&m);
	fo(i,1,n)
	{
		scanf("%s",s+1);
		fo(j,1,m)
		{
			a[i][j] = s[j] - '0';
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
		}
	}
}

int get(int x1,int y1,int x2,int y2)
{
	return sum[x2][y2] - sum[x2][y1-1] -sum[x1-1][y2] + sum[x1-1][y1-1];
}

bool check(int d,int x1,int x2,int x3)
{
	int ret = 0 , last = 1;
	fo(r,1,m)
	{
		if (get(1,last,x1,r)>=d && get(x1+1,last,x2,r)>=d && get(x2+1,last,x3,r)>=d && get(x3+1,last,n,r)>=d)
		{
			ret++; last = r+1;
		}
	}
	if (ret >= 4) return 1;else return 0;
}

bool check(int d)
{
	fo(i,1,n-1)
		fo(j,i+1,n-1)
			fo(k,j+1,n-1)
			if (check(d,i,j,k)) return 1;
	return 0;
}

void Work()
{
	int l = 0 , r = 5625 , ans;
	while (l<=r)
	{
		int mid = (l+r) >> 1;
		if (check(mid)) ans = mid , l = mid+1 ;else r = mid-1;
	}
	printf("%d\n",ans);
}

int main()
{
	/*freopen("cake.in","r",stdin); freopen("cake.out","w",stdout);*/
	
	Init();
	Work();
	
	return 0;
}
