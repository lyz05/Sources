#include <cstdio>
#include <cstring>
#include <algorithm>
#include <windows.h>

using namespace std;

const int N=2000+2,M=8,oo=2139062143;
int ans[N][N][4],s[4*N*N][3],n,m;
long long box[4],inf[N][N];
bool map[N][N];

int get(long long x,int y)
{
	x>>=m*m-y;
	return x%2;
}

void prepar()
{
	for (int i=m;i<=n;i++)
		for (int j=m;j<=n;j++)
		{
			for (int k=m-1;k>=0;k--)
				for (int l=m-1;l>=0;l--)
				{
					inf[i][j]=(inf[i][j]<<1)+map[i-k][j-l];
				}
		}
}

void init()
{
	scanf("%d %d\n",&n,&m);
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++)
		{
			char x;
			scanf("%c",&x);
			box[0]<<=1;
			box[0]+=x-48;
		}
		scanf("\n");
	}
	for (int i=m;i>0;i--)
		for (int j=0;j<m;j++)
		{
			box[1]<<=1;
			box[1]+=get(box[0],j*m+i);
		}
	long long t0=box[0],t1=box[1];
	for (int i=1;i<=m*m;i++)
	{
		box[2]=(box[2]<<1)+t0%2;
		t0>>=1;
		box[3]=(box[3]<<1)+t1%2;
		t1>>=1;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char ch;
			scanf("%c",&ch);
			map[i][j]=ch-48;
		}
		scanf("\n");
	}
}

int bfs()
{
	memset(ans,-1,sizeof ans);
	int l=1,r=1;
	ans[m][m][0]=0;
	s[1][0]=s[1][1]=m;s[1][2]=0;
	for (l=1;l<=r;l++)
	{
		int x=s[l][0],y=s[l][1],z=s[l][2],d=ans[x][y][z]+1;
		int nxt=z+1>3?0:z+1,lst=z-1<0?3:z-1;
		if (ans[x][y][nxt]==-1 && !(inf[x][y]&box[nxt]))
		{
			ans[x][y][nxt]=d;r++;
			s[r][0]=x;s[r][1]=y;s[r][2]=nxt;
		}
		if (ans[x][y][lst]==-1 && !(inf[x][y]&box[lst]))
		{
			ans[x][y][lst]=d;r++;
			s[r][0]=x;s[r][1]=y;s[r][2]=lst;
		}
		if (x-1>=m && ans[x-1][y][z]==-1 && !(inf[x-1][y]&box[z]))
		{
			ans[x-1][y][z]=d;r++;
			s[r][0]=x-1;s[r][1]=y;s[r][2]=z;
		}
		if (y-1>=m && ans[x][y-1][z]==-1 && !(inf[x][y-1]&box[z]))
		{
			ans[x][y-1][z]=d;r++;
			s[r][0]=x;s[r][1]=y-1;s[r][2]=z;
		}
		if (x+1<=n && ans[x+1][y][z]==-1 && !(inf[x+1][y]&box[z]))
		{
			ans[x+1][y][z]=d;r++;
			if (x+1==n && y==n) return d;
			s[r][0]=x+1;s[r][1]=y;s[r][2]=z;
		}
		if (y+1<=n && ans[x][y+1][z]==-1 && !(inf[x][y+1]&box[z]))
		{
			ans[x][y+1][z]=d;r++;
			if (x==n && y+1==n) return d;
			s[r][0]=x;s[r][1]=y+1;s[r][2]=z;
		}
	}
	return -1;
}

void print()
{
	int anss;
	for (int i=0;i<4;i++) anss=min(anss,ans[n][n][i]);
	if (anss==oo) printf("-1\n"); else printf("%d\n",anss);
}

int main()
{
	freopen("4095.in","r",stdin);
	init();
	prepar();
	int anss=bfs();
	printf("%d\n",anss);
	return 0;
}

