#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int M = 105;
int T,n,m;
char s[M][15],st[15],ts[15];
int a[M][M],len[M],w[M];
int dis,tmp,val,ans,mdis;

int match(int x,int y)
{
	for (int i=0;i<len[x];i ++)
	{
		int j=0;
		for (;j<len[y] && i+j<len[x] && s[x][i+j]==s[y][j];j ++);
		if (i+j==len[x]) return j;
	}
	return 0;
}

void prepar()
{
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=n;j ++)
		if (i!=j) a[i][j] = -match(i,j);
}

void dfs(int x)
{
	char now[15];
	memcpy(now,ts,sizeof ts);
	if (dis+len[x]>n) return;
	dis += len[x];
	val += w[x];
	if (val>ans || (val==ans && dis<=mdis))
	{
		ans = val;mdis = dis;
		memcpy(st,ts,sizeof ts);
	}
	for (int y=1;y<=m;y ++)
	{
		dis += a[x][y];
		strcat(ts,s[y]-a[x][y]);
		dfs(y);
		memcpy(ts,now,sizeof now);
		dis -= a[x][y];
	}
	dis -= len[x];
	val -= w[x];
}

int compare(const void*elem1,const void *elem2)
{return(strcmp((char*)elem1,(char*)elem2));}

//str为char类型二维数组如str[1000][9], 那么，size是字符串的数目（1000）， len是字符串的最长长度（9）
int main()
{
	freopen("1055.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&T);
	while (T --)
	{
		ans = 0;mdis = 0;
		memset(s,125,sizeof s);
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i ++) scanf("%s",s[i]);
		qsort(s,M,15,compare);
		for (int i=1;i<=m;i ++) len[i]=strlen(s[i]),scanf("%d",&w[i]);
		prepar();
		for (int i=1;i<=m;i ++) 
		{
			memcpy(ts,s[i],sizeof s[i]);
			dfs(i);
		}
		printf("%s\n",st);
	}

	return 0;
}

