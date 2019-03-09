#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int a,b,n;
long double c,ans;

int main()
{
	scanf("%d%d%d",&a,&b,&n);
	ans = 1.0*a/b;
	ans = ans - floor(ans);
	for (int i=1;i<n;i ++) ans *= 10,ans = ans - floor(ans);
	ans = ans - floor(ans);
	ans *= 1000;
	if ((int)ans/100==0) printf("0");
	if ((int)ans/10==0) printf("0");
	printf("%d\n",(int)floor(ans));
	return 0;	
} 
//1 1 2 3 5 8 13
