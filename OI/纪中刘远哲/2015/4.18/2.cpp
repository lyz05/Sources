#include <cstdio>

using namespace std;

const int N=15+5;
int n,k,a[N],ans,cnt;

int main()
{
	freopen("2.in","r",stdin);

	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);

	ans = 1;
	while (cnt<k)
	{
		++ ans;
		bool flag = 0,p = 0;
		for (int i=1;i<=n;i++) 
			if (ans%a[i]==0){
				if (!p) flag = 1;else flag = 0;
				if (!p)	p = 1;
			}
		if (flag) cnt ++;
	}
	printf("%d\n", ans);

	return 0;
}
