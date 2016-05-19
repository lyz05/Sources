#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

void work(int a,int b)
{
	if (a==b) return 1;
	if (b-a>0) p = 1;else p = -1;
	return abs(b-a)/d;
}

int main()
{
	freopen("4303.in","r",stdin);
	//freopen("4303.out","w",stdout);

	scanf("%d %d %d %d",&n,&d,&a,&b);
	len = work(a,b);

	return 0;
}
