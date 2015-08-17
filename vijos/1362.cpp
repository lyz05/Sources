#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=301;

int tmp,A,B,C,n,s,list[N],a[N][N];
bool v[N];

void dfs(int x,int &len,int &id)
{
	if (tmp>len)
	{
		len=tmp;
		id=x;
	}
	for (int i = 1;i <= n;i ++)
	{
		if ((a[x][i]>0) && (!v[i]))
		{
			v[i]=true;
			tmp+=a[x][i];
				dfs(i,len,id);
			tmp-=a[x][i];
			v[i]=false;
		}
	}
}

bool dis(int x,int y)
{
	if (x==y) return 1;
	for (int i=1;i<=n;i++)
	{
		if (!v[i] && a[x][i]>0)
		{
			v[i]=true;
			list[++ list[0]]=i;
			if (dis(i,y)) return 1;
			list[-- list[0]]=0;
			v[i]=false;
		}
	}
}

int main()
{
	freopen("1362.in","r",stdin);

	scanf("%d %d",&n,&s);
	for (int i = 1;i < n;i ++)
	{
		int x,y,v;
		scanf("%d %d %d",&x,&y,&v);
		a[x][y] = v;a[y][x] = v;
	}

	tmp=0;
	int len=0;
	v[1]=1;
	dfs(1,len,A);
	v[1]=0;

	len=0;v[A]=1;
	dfs(A,len,B);
	list[++ list[0]]=A;v[A]=0;
	dis(A,B);

	memset(v,0,sizeof v);
	int j=1,ans=(1<<30);len=0;
	v[list[j]]=1;
	for (int i=1;i<=list[0];i++)
	{
		if (i>1) v[list[i-1]]=0,len=0,v[list[i]]=1,j=i;
		while ((len+a[list[j]][list[j+1]]<=s) && (j+1<=list[0])) 
		{
			len+=a[list[j]][list[j+1]];
			j ++;
			v[list[j]]=1;
		}
		int anss=0;
		for (int k=i;k<=j;k++)
		{
			int dis=0;
			dfs(list[k],dis,C);
			if (dis>anss) anss=dis;
		}
		if (anss<ans) ans=anss;
	}
	printf("%d\n",ans);
	return 0;
}
