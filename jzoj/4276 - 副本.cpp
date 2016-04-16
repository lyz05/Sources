#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 100000;
int n;
LL tmp,ans;
struct node
{
	int val,id;
} a[N];
int L[N],R[N];
bool vis[N];

bool cmp(node A,node B) {return (A.val>B.val || (A.val==B.val && A.id<B.id));}

bool judge(int enl,int enr)
{
	//if (enr==0) return 0;
	return (L[enl]>R[enr]);
}

void work()
{
	memset(L,0,sizeof L);
	memset(R,0,sizeof R);
	sort(a+1,a+1+n,cmp);
	int stl,str,enl,enr;
	stl=1;str=0;
	enl=1;enr=0;
	L[1]=a[1].id;
	int i = 2;
	for (int sa=1;i<=n;sa^=1,i ++)
	{
		if (sa) L[++ enl] = a[i].id; else R[++ enr] = a[i].id;
		if (a[i].val==a[i-1].val || i==n) 
		{
			if ((enr!=0 && L[enl]>R[enr]) || (enr==0 && L[enl]>L[1]) || (tmp!=0&&a[i].id<tmp&&(!sa))
			|| (tmp!=0&&a[i].id>tmp&&(sa)))
			{
				int i,j;
				for (i=stl+1,j=str+1;i<=enl||j<=enr;i ++,j ++)
				{
					swap(L[i],R[j]);
				}
				i=enr-str,j=enl-stl;
				enl = stl + i;
				enr = str + j;
			}
			stl = enl,str = enr;
		} else tmp = L[(sa)?enl-1:enl];
	}
	for (int i=enl;i>=1;i --) printf("%d ",L[i]);
	for (int i=1;i<=enr;i ++) printf("%d ",R[i]);
	puts("");
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
		work();
	}

	return 0;
}

