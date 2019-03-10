#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m;
double ans;
int main()
{
	scanf("%d %d",&n,&m);
	printf("%d/",n);
	if (m<0) printf("(%d)=",m);
	else printf("%d=",m);
	if (m==0) printf("Error");
	else printf("%.2f",n*1.0/m);
	return 0;
} 
