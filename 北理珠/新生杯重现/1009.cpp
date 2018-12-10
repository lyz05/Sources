#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 1000000+5;
bool hash[N];
int T;

int main()
{
	scanf("%d",&T);
	while (T --)
	{
		memset(hash,0,sizeof hash);
		while (1)
		{
			int x;
			scanf("%d",&x);
			if (x==0) break;
			hash[x] ^= 1;
		}
		bool flag = 0;
		for (int i=1;i<=N-5;i ++) 
			if (hash[i])
			{
				printf("%d\n",i);
				flag = 1;
				break;
			}
		if (!flag) printf("Yes\n");
	}
	return 0;
} 
