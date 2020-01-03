#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 25,M = 1000;
int n,ans;
char ch,s[N][M];
int a[N];

void dfs(int x,int len)
{
	if (a[x]>2) return;
	if (len>ans)
		ans = len;
	
	for (int j=1;j<len;j ++)
	{
		for (int i=1;i<=n;i ++)
		{
			if (a[i]==2 || strlen(s[i])<=j) continue;
			bool flag = 1;
			int lenx = strlen(s[x]);
			for (int k=0;k<j && flag;k ++)
				if (s[x][lenx-j+k]!=s[i][k]) flag = 0;
			if (flag) 
			{
				a[i] ++;
				dfs(i,len+strlen(s[i])-j);
				a[i] --;
			}
		}
	}
}

int main()
{
	freopen("1311.in","r",stdin);
	//freopen("1311.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%s",s[i]);
	scanf("\n%c",&ch);
	
	for (int i=1;i<=n;i ++)
	if (s[i][0]==ch) 
	{
		a[i] = 1;
		dfs(1,strlen(s[i]));
		a[i] = 0;
	}
	printf("%d\n",ans);
	return 0;
}
