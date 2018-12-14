#include <cstdio>
#include <cstdlib>
#include <cstring>

//const int N = 1000000+5;
//bool hash[N];
int T,ans;

int main()
{
	scanf("%d",&T);
	while (T --)
	{
		//memset(hash,0,sizeof hash);
		ans = 0;
		while (1)
		{
			int x;
			scanf("%d",&x);
			if (x==0) break;
			ans ^= x;
		}
		if (ans==0) printf("Yes\n"); else printf("%d\n",ans);
	}
	return 0;
} 
