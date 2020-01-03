#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	//freopen("mission.in","r",stdin);
	//freopen("mission.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=2;i<=floor(sqrt(n));i ++)
		if (n % i == 0) printf("NO\n");
	printf("YES\n");
	return 0;
}
