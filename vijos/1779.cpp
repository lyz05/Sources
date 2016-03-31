#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1005,M = 5005,mo = 10;
struct node
{
	int x,y;
} a[N];
struct bign
{
	int len,num[M];
	bign()
	{
		memset(num,0,sizeof num);
		len = 1;
	}
	void operator = (int k)
	{
		bign ret;
		ret.len = 0;
		while (k)
		{
			ret.num[++ ret.len] = k%mo;
			k /= mo;
		}
		*this = ret;
		//return ret;
	}
	bign operator * (int k)
	{
		bign ret;
		for (int i=1;i<=len;i ++)
		{
			ret.num[i] += num[i]*k;
			ret.num[i+1] += ret.num[i]/mo;
			ret.num[i] %= mo;
		}
		for (ret.len=len;ret.num[ret.len+1];ret.len ++)
		{
			ret.num[ret.len+2] += ret.num[ret.len+1]/mo;
			ret.num[ret.len+1] %= mo;
		}
		return ret;
	}
	bign operator / (int k)
	{
		bign ret;
		int now=0;
		for (int i=len;i;i --)
		{
			ret.num[i] = (now*mo+num[i])/k;
			now = (now*mo+num[i])%k;
		}
		for (ret.len=len;!ret.num[ret.len];ret.len --);
		return ret;
	}
	bool operator < (bign B)
	{
		if (len!=B.len) return len<B.len;
		for (int i=len;i;i --)
		{
			if (num[i]!=B.num[i]) 
				return num[i]<B.num[i];
		}
		return 0;
	}
	void print()
	{
		for (int i=len;i;i --)
			printf("%d",num[i]);
		printf("\n");
	}
} ret,ans;
int n;
bool cmp(node A,node B)
{
	return A.x*A.y<B.x*B.y;
}

int main()
{
	freopen("1779.in","r",stdin);
	//freopen("1779.out","w",stdout);

	scanf("%d%d%d",&n,&a[0].x,&a[0].y);
	for (int i=1;i<=n;i ++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);

	ret = a[0].x;
	ans = 0;
	for (int i=1;i<=n;i ++)
	{
		bign t = ret/a[i].y;
		if (ans<t) ans = t;
		ret = ret*a[i].x;
	}
	ans.print();
	return 0;
}
