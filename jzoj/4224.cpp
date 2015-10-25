#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 200+5,M = 50000+100+5,oo=1e9+7;
int n,m,p,pp,ans,mm;
int v[N],w[N],num[N];
int s[M][2],f[N][M];

int work1()
{
	int ans = oo,maxj = pp+100;
	for (int j=0;j<=maxj;j ++) f[0][j] = oo;
	f[0][0] = 0;
	for (int i=1,p=0,q=1;i<=n;i ++ ,p ^= 1, q ^= 1)
	{
		//for (int j=0;j<=maxj;j ++) f[q][j] = oo;
		// j = 1 to p
		int d = v[i];//按容量分
		for (int b = 0;b <= d-1; b ++) //枚举余数
		{
			int l = 1,r = 0;
			for (int a = 0;a <= maxj/d;a ++) //枚举倍数
			{
				int j = a*d+b;	//原始的j
				if (j>maxj) break;
				m = min(num[i],j / v[i]);
				int ret = f[p][a*d+b] - a * w[i];
				while (l<=r && s[r][1]>=ret) r --;
				s[++ r][1] = ret;
				s[r][0] = a;
				//插入f[i-1]状态
				while (l<=r && s[l][0]<(a-m)) l ++;
				f[q][j] = s[l][1] + a*w[i];
				//取出
				if (i==n && j>=pp) ans = min(ans,f[q][j]);
			}
		}
	}
	return ans;
}

int work2(int st)
{
	int maxj = M - 5;
	for (int j=0;j<=maxj;j ++) f[0][j] = 0;
	//f[0][0] = 0;
	for (int i=1,p=0,q=1;i<=mm;i ++ ,p ^= 1, q ^= 1)
	{
		//for (int j=0;j<=maxj;j ++) f[q][j] = oo;
		// j = 1 to p
		int d = v[i];//按容量分
		for (int b = 0;b <= d-1; b ++) //枚举余数
		{
			int l = 1,r = 0;
			for (int a = 0;a <= maxj/d;a ++) //枚举倍数
			{
				int j = a*d+b;	//原始的j
				if (j>maxj) break;
				m = min(num[i],j / v[i]);
				int ret = f[p][a*d+b] - a * w[i];
				while (l<=r && s[r][1]<=ret) r --;
				s[++ r][1] = ret;
				s[r][0] = a;
				//插入f[i-1]状态
				while (l<=r && s[l][0]<(a-m)) l ++;
				f[q][j] = s[l][1] + a*w[i];
				//取出
			}
		}
		if (i==mm)
			for (int j=0;j<=50000;j ++)
				if (f[q][j]>=st && j<=50000) return j;
	}

	return -1;
}

int main()
{
	freopen("4224.in","r",stdin);

	int T;
	scanf("%d",&T);
	while (T --)
	{
		//ans = 0;
		scanf("%d%d%d",&n,&mm,&pp);
		for (int i=1;i<=n;i ++)
			scanf("%d%d%d",v + i,w + i,num + i);
		ans = work1();
		printf("%d\n",ans);
		for (int i=1;i<=mm;i ++)
			scanf("%d%d%d",w + i,v + i,num + i);
		/*
		if (ans==oo) {puts("TAT");continue;}
		ans = work2(ans);
		if (ans==-1) {puts("TAT");continue;}
		printf("%d\n",ans);
		*/
	}
	return 0;
}
