#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1e5+5, NUM = 30;
const int S[NUM] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777};
struct node
{
	int tag,num[10000+10],l,r;
} h[1005];
char s[10];
int l,r,v,n,m,size;
int a[N];

bool judge(int x)
{
	for (;x;x /= 10) 
		if (x % 10 != 4 && x % 10 != 7) 
			return 0;
	return 1;
}

void make()
{
	for (int i=0;i<=n/size+1;i ++)
	{
		int j=1;
		h[i].tag = 0;
		h[i].l = i*size+1;
		for (j=1;j<=size && i*size+j<=n;j ++)
		{
			h[i].num[a[i*size+j]] ++;
		}
		h[i].r = i*size+j-1;
	}
}

void add(int l,int r,int val)
{
	int j = l%size==0?l/size-1:l/size,k = r%size==0?r/size-1:r/size;
	if (j==k)
	{
		for (int i=l;i<=r;i ++)
		{
			h[j].num[a[i]] --;
			a[i] += val;
			h[j].num[a[i]] ++;
		}
		return;
	}
	for (int i=l;i<=h[j].r;i ++)
	{
		h[j].num[a[i]] --;
		a[i] += val;
		h[j].num[a[i]] ++;
	}
	for (int i=j+1;i<=k-1;i ++)
	{
		h[i].tag += val;
	}
	for (int i=h[k].l;i<=r;i ++)
	{
		h[k].num[a[i]] --;
		a[i] += val;
		h[k].num[a[i]] ++;
	}
}

int query(int l,int r)	//??
{
	int ret = 0;
	int j = l%size==0?l/size-1:l/size,k = r%size==0?r/size-1:r/size;
	if (j==k)
	{
		for (int i=l;i<=r;i ++)
		{
			int tmp = a[i] + h[j].tag;
			for (int i=0;i<NUM;i++) 
			if (S[i] == tmp)
			{
				ret ++;
				break;
			}
		}
		return ret;
	}
	for (int i=l;i<=h[j].r;i ++)
	{
		int tmp = a[i] + h[j].tag;
		for (int i=0;i<NUM;i++) 
			if (S[i] == tmp)
			{
				ret ++;
				break;
			}
	}
	for (int i=j+1;i<=k-1;i ++)
	{
		for (int j=0;j<NUM;j ++)
		{
			int tmp = S[j]-h[i].tag<0?0:S[j]-h[i].tag;
			ret += h[i].num[tmp];
		}
	}
	for (int i=h[k].l;i<=r;i ++)
	{
		int tmp = a[i] + h[k].tag;
		for (int i=0;i<NUM;i++) 
			if (S[i] == tmp)
			{
				ret ++;
				break;
			}
	}
	return ret;
}

int main()
{
	freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++)
		scanf("%d",a + i);
	
	size = floor(sqrt(n));
	make();
	while (m --)
	{
		scanf("%s%d%d",s,&l,&r);
		if (s[0]=='a')
		{
			scanf("%d",&v);
			add(l,r,v);
		} else
		{
			int ans = 0;
			ans = query(l,r);
			printf("%d\n",ans);	
		}
	}

	return 0;
}
