#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 5,M = 44000000/4;
typedef int Matrix[N][N];
struct node
{
	int kind,st,step;
	//node(int a,int b,int c) {kind = a,st = b,step = c;}
} buffer[M];

char s[N];
int n,m,ans,l,r;
Matrix st,en,tmp;
const int col[2][4]={{2,0,1},{1,2,0}};
//map <char,int> p;
int f[2][M],H[M];
//map <int,int> f[2];
//queue <node> buffer[2];

int calc(Matrix &a)
{
	int ret = 0;
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=m;j ++)
			ret = ret*3+a[i][j];
	return ret;
}

void get(node x)
{
	int st = x.st;
	for (int i=n;i;i --)
	for (int j=m;j;j --)
	{
		tmp[i][j] = st%3;
		st /= 3;
	}
}

int Hash(int t){
	int mo = M - 10, x = t;
	t = t % mo + 1;
	while(H[t] != 0 && H[t] != x) t = t % mo + 1;
	H[t] = x;
	return t;
}

void push(int K,int step)
{
	int st = calc(tmp),t = Hash(st);
	if (f[K][t]) return; 
	r=r%M+1;
	buffer[r].kind = K;
	buffer[r].st = st;
	buffer[r].step = step+1;
	if (f[K^1][t]>0)
	{
		ans = min(step+1+f[K^1][t]-1,ans);
		return;
	}
	f[K][t] = step+1+1;
}



void bfs()
{
	//f[0].clear();f[1].clear();
	/*
	queue <node> tt1;
	swap(buffer[1],tt1);
	queue <node> tt0;
	swap(buffer[0],tt0);
	*/
	//if (!buffer[1].empty()) printf("asdnasdjas");
	memset(f,0,sizeof f);
	memset(H,0,sizeof H);

	int st1=calc(st),st2=calc(en);
	l = 1,r = 2;
	buffer[1].st = st1;
	buffer[2].st = st2;
	buffer[2].kind = 1;
	f[0][Hash(st1)] = 1;f[1][Hash(st2)] = 1;
	if (st1==st2) {ans = 0;return ;}
	for (;l!=r+1;l=l%M+1)
	{
		//if (buffer[0].empty() && buffer[1].empty()) return;
		//if (buffer[K].empty()) continue;
		//int size = buffer[K].size();
		int K = buffer[l].kind;
		node now = buffer[l];
		int step = now.step;
		for (int i=1;i<n;i ++)
		for (int j=1;j<m;j ++)
		for (int k=0;k<2;k ++)
		{
			if (ans==1e9+7){
			get(now);
			if (!k) //bug
			{
				int Tmp;
				if (!K)
				{
				Tmp = tmp[i][j];	
				tmp[i][j] = tmp[i+1][j];tmp[i+1][j] = tmp[i+1][j+1];
				tmp[i+1][j+1] = tmp[i][j+1];tmp[i][j+1] = Tmp;
					push(K,step);
				Tmp = tmp[i][j];
				tmp[i][j] = tmp[i][j+1];tmp[i][j+1] = tmp[i+1][j+1];
				tmp[i+1][j+1] = tmp[i+1][j];tmp[i+1][j] = Tmp;
				} else 
				{
				Tmp = tmp[i][j];
				tmp[i][j] = tmp[i][j+1];tmp[i][j+1] = tmp[i+1][j+1];
				tmp[i+1][j+1] = tmp[i+1][j];tmp[i+1][j] = Tmp;
					push(K,step);
				Tmp = tmp[i][j];
				tmp[i][j] = tmp[i+1][j];tmp[i+1][j] = tmp[i+1][j+1];
				tmp[i+1][j+1] = tmp[i][j+1];tmp[i][j+1] = Tmp;
				}
			} else 
			{
				for (int tx=0;tx<2;tx ++)
				for (int ty=0;ty<2;ty ++)
				{
					tmp[i+tx][j+ty] = col[K][tmp[i+tx][j+ty]];
				}
					push(K,step);
				for (int tx=0;tx<2;tx ++)
				for (int ty=0;ty<2;ty ++)
				{
					tmp[i+tx][j+ty] = col[K^1][tmp[i+tx][j+ty]];
				}
			
			}
			}

		}
		if (now.step!=buffer[l%M+1].step && ans!=1e9+7) return; 
	}
}

int main()
{
	freopen("1085.in","r",stdin);
	//freopen(".out","w",stdout);

	//p['R'] = 0,p['G'] = 1,p['B'] = 2;
	while (1)
	{
		//memset(st,0,sizeof st);
		//memset(en,0,sizeof en);
		scanf("%d%d",&n,&m);
		if (n==0) return 0;
		for (int i=1;i<=n;i ++) 
		{
			scanf("%s",s+1);
			for (int j=1;j<=m;j ++)
			{
				if (s[j]=='R') st[i][j] = 0;
				else if (s[j]=='G') st[i][j] = 1;
				else st[i][j] = 2;
			}
		}
		for (int i=1;i<=n;i ++) 
		{
			scanf("%s",s+1);
			for (int j=1;j<=m;j ++)
			{
				if (s[j]=='R') en[i][j] = 0;
				else if (s[j]=='G') en[i][j] = 1;
				else en[i][j] = 2;
			}
		}
		ans = 1e9+7;
		bfs();
		if (ans==1e9+7) printf("-1\n"); else printf("%d\n",ans);
	}
	return 0;
}
