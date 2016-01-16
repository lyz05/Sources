#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 20,INF = 1e9+7;
struct point
{
	int x,y;
} P[N];
int n,begin;
double f[1<<N];

int sqr(int x) {return x*x;}
double dist(point A,point B)
{
	return sqrt(1.0*sqr(A.x-B.x)+sqr(A.y-B.y));
}

double fix(int st,int cur)
{
	double ret = 0;
	bool mark[N];double dis[N];
	for (int i=0;i<n;i ++)
	{
		if ((1<<i) & st)
		{
			mark[i] = 1;
			dis[i] = dist(P[i],P[cur]);
		} else	mark[i] = 0;
	}
	for (int i=0;i<2;i ++)
	{
		double Min = INF;
		int p = 0;
		for (int j=0;j<n;j ++)
			if (mark[j] && dis[j]<Min)
			{
				Min = dis[j];
				p = j;
			}
		ret += Min;
		mark[p] = 0;
	}
	if (ret>=INF) return -1;
	return ret;	
}

int main()
{
	//freopen("1121.in","r",stdin);
	//freopen(".out","w",stdout);

	while (scanf("%d",&n),n)
	{
		begin = 0;
		for (int i=0;i<n;i ++)
		{
			int kind;
			scanf("%d%d%d",&P[i].x,&P[i].y,&kind);
			if (kind) begin += (1<<i);
		}
		for (int i=0;i<(1<<n);i ++) f[i] = INF;
		f[begin] = 0;
		for (int i=0;i<(1<<n);i ++)
		{
			if (f[i]==INF) continue;
			for (int j=0;j<n;j ++)
			{
				if (i & (1<<j)) continue;
				double sum = fix(i,j);
				if (sum>=0) 
					f[i|(1<<j)] = min(f[i]+sum,f[i|(1<<j)]);
			}
		}
		if (f[(1<<n)-1]==INF) printf("No Solution\n");
		else printf("%.6f\n",f[(1<<n)-1]);
	}
	return 0;
}
