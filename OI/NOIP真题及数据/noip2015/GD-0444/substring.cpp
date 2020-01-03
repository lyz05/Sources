#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1000+5,mo = 1e9+7;
char s1[N],s2[N];
int n,m,k,ans;

void judge(int st,int L,int R,int last)
{
	int len = R-L+1;
	for (int i=last;i<=n;i ++)
	{
		bool flag = 1;
		int j;
		for (j=i;j<=i+len-1;j ++)
			if (s1[j]!=s2[j-i+L]) {flag = 0;break;}
		if (flag) 
		{
			if (st==1) judge(2,R+1,m,j);
			else 
				ans = (ans+1)%mo;
		}
	}
}

void dfs(int i,int j)
{
	if (j>m) 
	{
		ans = (ans+1)%mo;
		return;
	}
	if (i>n) return;
	if (s1[i]==s2[j]) 
		dfs(i+1,j+1);
	dfs(i+1,j);
}

void work(int k)
{
	if (k==1)
	{
		for (int i=1;i<=n;i ++)
		{
			bool flag = 1;
			for (int j=i;j<=i+m-1;j ++)
				if (s1[j]!=s2[j-i+1]) {flag = 0;break;}
			if (flag) ans = (ans+1) % mo;
		}
	}
	if (k==2)
	{
		for (int i=1;i<=m-1;i ++)
		{
			judge(1,1,i,1);
		}
	}
	if (k==m)
	{
		dfs(1,1);
	}
}

int main()
{
	freopen("substring.in","r",stdin);
	freopen("substring.out","w",stdout);

	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	ans = 0;
	work(k);
	printf("%d\n",ans);
	return 0;
}

