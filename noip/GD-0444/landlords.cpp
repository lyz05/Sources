#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int inf[]={14,12,13,1,2,3,4,5,6,7,8,9,10,11};
const int fni[]={3,4,5,6,7,8,9,10,11,12,13,1,2,0};

const int N = 25,M = 14;
int T,n,ans,len,tot,Len,Tot,k,kk,maxx;
int a[N],num[20];

bool cmp(int x,int y)
{
	return inf[x]<inf[y];
}
/*
void dfs(int dep)
{
	int tmp = 0;
	for (int i=1;i<=n;i ++)
	{
		if (a[i]==-1 || num[a[i]]==0) continue;
		for (int j=1;j<=11;j ++)
		{
			if ((j==1) && a[i]==0 && num[a[i]]==2) 
			{
				num[a[i]] -= 2;
				tmp = a[i];
				a[i] = -1,a[i+1] = -1;
				dfs(dep+1);
				a[i] = tmp,a[i+1] = tmp;
				num[a[i]] += 2;
			}
			if (j==2 && num[a[i]]==4) 
			{
				num[a[i]] -= 4;
				tmp = a[i];
				for (int k=i;k<=i+3;k ++) a[k] = -1;
				dfs(dep+1);
				for (int k=i;k<=i+3;k ++) a[k] = tmp;
				num[a[i]] += 4;
			}
			if (3<=j && j<=5 && num[a[i]]==j-2)
			{
				num[a[i]] -= j-2;
				tmp = a[i];
				for (int k=i;k<=i+j-3;k ++) a[k] = -1;
				dfs(dep+1);
				for (int k=i;k<=i+j-3;k ++) a[k] = tmp;
				num[a[i]] += j-2;
			}
			if (8<=j && j<=10)
			{
				for (int k=1;k<=j-7)
					for (int l=a[i];;l=fni[inf[l]+1])
			}
		}
	}
}
*/
int main()
{
	freopen("landlords.in","r",stdin);
	freopen("landlords.out","w",stdout);
	
	scanf("%d%d",&T,&n);
	while (T --)
	{
		for (int i=1;i<=n;i ++)
		{	
			int x,y;
			scanf("%d %d",&x,&y);
			a[i] = x;
			num[inf[x]] ++;
		}
		sort(a+1,a+1+n,cmp);
				
		if (num[inf[0]]==2) num[inf[0]] = 0,ans ++;
		for (int i=1;i<=M-1;i ++) 
			if (num[i]==4) num[i] = 0,ans ++;
		while (1)
		{
			len = 0;tot = 1e9+7,k=0;
			Len = 0,Tot = 0,kk = 0;
			maxx = 0;
			for (int i=1;i<=M-2;i ++)
			{
				if (num[i]==0)
				{
					len=0,tot=1e9+7,k=i;
					continue;
				}
				len ++;
				tot = min(tot,num[i]);
				if ((tot==1 && len>=5)||(tot==2 && len>=3)||(tot==3 && len>=2)) 
				{
					if (tot*len>maxx) 
					{
						maxx = tot*len;
						kk = k;
						Len = len;
						Tot = tot;
					}
				}
			}
			if (kk)
			{
				//num[kk+1]
				ans ++;
				for (int i=kk+1;i<=kk+Len;i ++) num[i] -= Tot;
			} else break;
		}
		for (int i=1;i<=M;i ++)
			if (num[i])
			{
				for (int j=3;j>=1;j --)
				{
					ans += num[i]/j;
					num[i] %= j;
				}
			}
		
		printf("%d\n",ans);
		//dfs(1);
	}

	return 0;
}

