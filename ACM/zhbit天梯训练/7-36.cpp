#include<cstdio>
#include<algorithm>
using namespace std;

int p1,p2,a,b,c;
//char sh[5],sm[5];
int main()
{
	scanf("%d%d%d%d%d",&p1,&p2,&a,&b,&c);
	int t;
	t = a+b+c;
	if (t==0) printf("The winner is a: %d + 3",p1);
	else
	if (t==3) printf("The winner is b: %d + 3",p2);
	else
	if (p1>p2) printf("The winner is a: %d + %d",p1,3-t);
	else printf("The winner is b: %d + %d",p2,t);
	 
	return 0;
}
