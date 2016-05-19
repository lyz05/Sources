#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int n,m,ID;
int a[105];
map <int,int> p;

void work(int now,int limit)
{
	if (p[ID]!=1) p[ID] = now;
	for (int i=limit;i>=1;i --)
	{
		if (a[i]==ID) a[i] = 0;
	}
	if (now==2 && p[ID]!=1) a[limit]=ID;
}

void print(int limit)
{
	int tot = 0;
	for (int i=limit;i>=1 && tot<20;i --) 
		if (a[i]) printf("%d ",a[i]),tot ++;
	puts("");
}

int main()
{
	freopen("problem.in","r",stdin);
	freopen("problem.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++) 
	{
		int typ;
		scanf("%d",&typ);
		if (typ==3) print(i);else 
		{
			scanf("%d",&ID);
			if (ID>n || ID<1) continue;
			work(typ,i);
		}
	}

	return 0;
}
