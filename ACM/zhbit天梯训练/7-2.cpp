#include<cstdio>
#include<algorithm>
using namespace std;

int h,m;
//char sh[5],sm[5];
int main()
{
	//scanf("%s:%s",sh,sm);
	//h = atoi(sh);
	//m = atoi(sm);
	scanf("%d:%d",&h,&m);
	if (h>12 || (h==12 && m>0))
	{
		h -= 12;
		h += (m>0);
		for (int i=1;i<=h;i ++) printf("Dang"); 
	} else 
	{
		printf("Only ");
		if (h<10) printf("0");
		printf("%d:",h);
		if (m<10) printf("0");
		printf("%d.  Too early to Dang.",m);
	}
	return 0;
}
