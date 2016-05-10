#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 100000;
int n,m,k,a[N];

bool cmp(int A,int B)
{
	return A>B;
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("mission.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i ++)
	{
		int num,val;
		scanf("%d%d",&num,&val);
		if (val>=2*k) a[i] = num;
	}
	sort(a+1,a+1+n,cmp);
	LL sum = 0;
	for (int i=1;i<=n;i ++)
	{
		sum += a[i];
		if (sum>=m) 
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}

