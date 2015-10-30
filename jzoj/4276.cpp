#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 100000;
int n,l,r;
struct node
{
	int val,id;
} a[N];
int ans[N];

bool cmp(node A,node B) 
{return (A.val<B.val || (A.val==B.val && A.id<B.id));}

void insert(int L,int R,int v)
{
	int i;
	if (L>R) return;
	for (i=L;i<=R;i ++)
		if (a[i].id<v)
			ans[++ l] = a[i].id;
		else break;
	for (int j=R;j>=i;j --)
		ans[-- r] = a[j].id;
}

void work()
{
	int i,j,sum;
	bool flag;
	l=0;r=n+1;
	i=1;
	while (i<=n)
	{
		j = i;
		while (j<n && a[j].val==a[j+1].val) j ++;
		sum = j-i+1;
		if (sum==1)
		{
			while (j<n && a[j+1].val!=a[j].val) j ++;
			if (j!=n) j--;

			flag = (a[i].id>a[i+1].id);
			
			for (int k=i;k<=j;k ++,flag^=1)
				if (flag)
				       	ans[-- r] = a[k].id;
				else	ans[++ l] = a[k].id;
			i = j+1;
			j = i;
			while (j<n && a[j].val==a[j+1].val) j ++;
			if (j>=i && i<=n)
			{
				ans[--r] = a[j].id,ans[++ l] = a[i].id;
				if (j>=n)
					insert(i+1,j-1,N);
				else	
					if (j+1>=n)
						insert(i+1,j-1,a[j+1].id);
					else	insert(i+1,j-1,min(a[j+1].id,a[j+2].id));
			}
			i = j+1;
		} else 
		{
			ans[-- r] = a[j].id;
			ans[++ l] = a[i].id;
			if (j>=n)
				insert(i+1,j-1,N);
			else
				if (j+1>=n)
					insert(i+1,j-1,a[j+1].id);
				else	insert(i+1,j-1,min(a[j+1].id,a[j+2].id));
		}	i = j+1;
	}
}

int main()
{
	freopen("permutation.in","r",stdin);
	//freopen("permutation.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i ++) 
		{
			scanf("%d",&a[i].val);
			a[i].id = i;
		}
		sort(a+1,a+1+n,cmp);
		work();
		for (int i=1;i<=n;i ++)
			printf("%d ",ans[i]);
		puts("");
	}

	return 0;
}

