#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 300000+5;
int n,k;
double ans;
int s[N],a[N];

int main()
{
	freopen("average.in","r",stdin);
	//freopen("average.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i ++) 
		scanf("%d",a+i) , s[i] = s[i-1] + a[i];
	
	for (int i=0;i<=n;i ++)
		for (int j=i+k;j<=n;j ++)
		{
			double tmp = (double)(s[j]-s[i])/(j-i);
			ans = max(ans,tmp);
		}
	printf("%.6f\n",ans);

	return 0;
}

