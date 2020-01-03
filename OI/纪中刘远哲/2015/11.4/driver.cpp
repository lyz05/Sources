#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 30;
int a[N],p[N],b[N];
int n,Time,tot,tmp,maxx,NN;

void calc(int dep,int mdep,int tmp)
{
	if (dep>mdep)
	{
		if (p[tmp] && p[tmp]!=Time) p[tmp]=Time,tot ++;
		return;
	}
	calc(dep+1,mdep,tmp+b[dep]);
	calc(dep+1,mdep,tmp);
}

void print(int x)
{
	printf("%d\n",x);
	for (int i=1;i<=x;i ++) printf("%d ",b[i]);
	puts("");
	exit(0);
}

void dfs(int dep,int mdep,int num,int last)
{
	if (dep>mdep)
	{
		tmp = 0;
		Time ++;tot = 0;
		calc(1,mdep,0);
		if (tot==NN) print(mdep);
		return;
	}
	if (dep==mdep)
	{
		if (num==0) return;
		b[dep] = num;
		dfs(dep+1,mdep,0,num);
		return;
	}
	for (int i=last+1;i<=num;i ++)
	{
		b[dep] = i;
			dfs(dep+1,mdep,num-i,i);
		b[dep] = 0;
	}
}

int main()
{
	freopen("driver.in","r",stdin);
	freopen("driver.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
	{
		scanf("%d",a + i);
		if (p[a[i]]) NN --;
		p[a[i]] = 1;
		NN ++;
		maxx = max(maxx,a[i]);
	}
	
	Time = 1;
	for (int i=1;i<=n;i ++) dfs(1,i,maxx,0);

	return 0;
}

