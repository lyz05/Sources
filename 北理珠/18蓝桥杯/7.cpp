#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5+7;
int a[N],b[N],ans[N];
int n,m,tot=0;

int main()
{
	//freopen("7.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)	scanf("%d",a + i);
	memcpy(b,a,sizeof a);
	sort(b+1,b+1+m);
	//init
	for (int i=0;i<m&&tot<n-m;i ++)
	{
		int now = b[i+1]-b[i]-1;
		for (int j=1;j<=now;j ++) ans[++ tot] = b[i]+j;
	}
	for (int i=1;tot<n-m;i ++)
		ans[++ tot] = b[m]+i;
	//work
	a[m+1] = 1e9+7;
	for (int i=1,j=1;i<=m+1;i ++)
	{
		for (;ans[j]<a[i]&&j<=tot;j ++) 
			printf("%d\n",ans[j]);
		if (i!=m+1) printf("%d\n",a[i]);
	}
	
	return 0;
} 
