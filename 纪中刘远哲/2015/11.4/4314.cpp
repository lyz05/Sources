#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 30;
int a[N],p[N],b[N];
int n,Time,tot,tmp,maxx,NN;

void print(int x)
{
	printf("%d\n",x);
	for (int i=1;i<=x;i ++) printf("%d ",b[i]);
	puts("");
	exit(0);
}

bool judge(int x,int sum,int dep,int mdep)
{
	if (x==sum) return 1;
	if (sum>x) return 0;
	if (dep>mdep) return 0;
	bool t1 = judge(x,sum+b[dep],dep+1,mdep);
	if (t1) return 1;
	bool t2 = judge(x,sum,dep+1,mdep);
	return t2;
}

void dfs(int dep,int mdep,int num,int last)
{
	if (dep>mdep)
	{
		tmp = 0;
		Time ++;tot = 0;
		for (int i=1;i<=n;i ++)
			if (a[i]!=a[i-1] && !judge(a[i],0,1,mdep)) return;
		print(mdep);
		return;
	}
	for (int i=last;i<=num;i ++)
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
		maxx = max(maxx,a[i]);
	}
	
	Time = 1;
	for (int i=1;i<=n;i ++) dfs(1,i,maxx,0);

	return 0;
}

