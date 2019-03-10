#include<cstdio>
#include<algorithm>
using namespace std;

int n;
//char sh[5],sm[5];
int main()
{
	scanf("%d",&n);
	n--;
	n+=2;
	n%=7;
	n++;
	printf("%d\n",n);
	return 0;
}
