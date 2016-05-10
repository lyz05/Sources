#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 60,mo = 998244353;
struct node
{
	int x,y;
} a[N];
bool dir[N][4];
int n,ans;
int f[2][N][N][N][N];

bool cmp(node A,node B)
{
	return (A.x<B.x || (A.x==B.x && A.y<B.y));
}

int getmax(int x , int y)
{
	if (x == 0) return y;
	return (a[x].y > a[y].y) ? x : y;
}
int getmin(int x , int y)
{
	if (x == 0) return y;
	return (a[x].y < a[y].y) ? x : y;
}

int main()
{
	freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a[i].x = u;a[i].y = v;
	}
	sort(a+1,a+1+n,cmp);

	for (int i=1;i<=n;i ++)
	for (int j=0;j<4;j ++)
	for (int k=1;k<=n;k ++)
		if (i!=k)
		{
			bool flag = 0;
			if (j==0 && a[i].x==a[k].x && a[i].y<a[k].y) flag = 1;
			if (j==1 && a[i].x==a[k].x && a[i].y>a[k].y) flag = 1;
			if (j==2 && a[i].y==a[k].y && a[i].x>a[k].x) flag = 1;
			if (j==3 && a[i].y==a[k].y && a[i].x<a[k].x) flag = 1;
			dir[i][j] = !flag;
			if (flag) break;
		}
	
	dir[0][0] = dir[0][1] = dir[0][2] = dir[0][3] = 1;
	int p=0,q=1;
	ans = 0;
	f[0][0][0][0][0] = 1;
	for (int i=0;i<=n;i ++,p^=1,q^=1)
	{
		int x = a[i+1].x,y = a[i+1].y;
		for (int aa=0;aa<=i;aa++)
		for (int b=0;b<=i;b++)
		for (int c=0;c<=i;c++)
		for (int d=0;d<=i;d++)
		{
			if (i == n) 
				ans = (ans + f[p][aa][b][c][d]) % mo;
			f[q][aa][b][c][d] = 0;
		}
		if (i==n) break;

		for (int aa=0;aa<=i;aa++)
		for (int b=0;b<=i;b++)
		for (int c=0;c<=i;c++)
		for (int d=0;d<=i;d++)
		{
			if (!f[p][aa][b][c][d]) continue;
			if (((a[b].y<y && y<a[aa].y) || (!aa && !b) || (!aa && a[b].y<y) || (!b && y<a[aa].y)) && dir[i+1][2])
				(f[q][aa][b][c][d] += f[p][aa][b][c][d]) %= mo;
			if ((y>a[c].y || !c) && dir[i+1][0]) 
				(f[q][getmin(aa,i+1)][b][c][d] += f[p][aa][b][c][d]) %= mo;
			if ((y<a[d].y || !d) && dir[i+1][1])
				(f[q][aa][getmax(b,i+1)][c][d] += f[p][aa][b][c][d]) %= mo;
			if (dir[i+1][3])
				(f[q][aa][b][getmax(c,i+1)][getmin(d,i+1)] += f[p][aa][b][c][d]) %= mo;
		}
	}

	printf("%d\n",ans);
	return 0;
}

