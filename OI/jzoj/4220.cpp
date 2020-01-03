#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
LL k,n,m,p;

int main()
{
	freopen("4220.in","r",stdin);
	
	scanf("%lld%lld%lld%lld",&k,&n,&m,&p);
	if (k == 1) print((m+n)*(n-m+1)/2)

	return 0;
}

