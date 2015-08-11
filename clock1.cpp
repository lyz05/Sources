#include<cstdio>
#include<time.h>

using namespace std;


void test()
{
	long long ans=1;
	int k=2;
	for(int i=1;i<=1e8;i++)
	{
		if (ans>1e6) k=-2;
	       	else if (ans<(-1e6)) k=2;
		ans+=k;
	}
	printf("%ld\n",ans);
}

int main()
{
	clock_t t1,t2;
	t1=clock();

	test();
	
	t2=clock();
	printf("%dms\n",t2-t1);
}
