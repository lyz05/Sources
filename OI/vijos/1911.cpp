#include <cstdio>
#include <cstring>

using namespace std;

const int N=100;
const int P=20000+5;
int a[N],n;
bool p[P];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(p,0,sizeof(p));
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			p[a[i]+a[j]]=1;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (p[a[i]]) ans++;
	printf("%d\n",ans);
	return 0;
}
