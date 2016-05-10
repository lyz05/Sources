#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 50;
const int dir[]={-1,1,1,-1,1,-1,-1,1};
int n,tmp,ans,a[N],b[N];

void dfs(int dep,int st,int n)
{
	if (dep>n)
	{
		if (abs(tmp)<ans)
		{
			ans = abs(tmp);
			memcpy(b,a,sizeof a);
		} 
		return;
	}
	for (int i=-1;i<=1;i += 2)
	{
		a[dep] = i;
		tmp += i*dep*dep;
			dfs(dep+1,i,n);
		tmp -= i*dep*dep;
		a[dep] = 0;
	}
}

int main()
{
	//freopen("five.in","r",stdin);
	//freopen("five.out","w",stdout);

	int tmp = 0;
	ans = 1e9+7;
	scanf("%d",&n);
	if (n<=20) dfs(1,0,n) , tmp = n;
	else 
	{
		tmp = n % 8+8;
		dfs(1,0,tmp);
	}
	printf("%d\n",ans);
	for (int i=1;i<=tmp;i ++)
		printf("%d ",b[i]);
	for (int i=tmp+1,j=0;i<=n;i ++,j = (j+1)%8)
		printf("%d ",dir[j]);
	puts("");
	return 0;
}

