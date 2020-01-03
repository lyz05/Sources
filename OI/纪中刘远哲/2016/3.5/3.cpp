#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

typedef long long LL;
LL A,B,K,a[2];
int T;
map <int,int> p;

LL gcd(LL a,LL b)
{
	if (!b) return a; else return gcd(b,a%b); 
}

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("3.out","w",stdout);

	scanf("%lld%lld",&A,&B);
	printf("%lld\n",gcd(A,B));
	


	return 0;
}
