//Problem F
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10+1;
int n,ans[N]={0,1,0,0,2,10,4,40,92,352,724};

int main()
{
	//freopen("F.in","r",stdin);
	while (1)
	{
		scanf("%d",&n);
		if (n==0) break;
		printf("%d\n",ans[n]);	
	}
	return 0;
}
