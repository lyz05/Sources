#include <cstdio>
#include <cstring>

using namespace std;

const int N=100,mo=100007;
int f[N][N];
char s[N];

int main()
{
	int t;
	scanf("%d",&t);
	for (int cnt = 1;cnt <= t;cnt ++)
	{
		scanf("%s",&s);
		int n = strlen(s);
		for (int i=0;i<n;i++)
		{
			f[i][i]=1;
			for (int j = i-1;j >= 0;j--)
			{
				f[j][i] = f[j+1][i]+f[j][i-1]-f[j+1][i-1];
				f[j][i] %= mo;
				if (s[j]==s[i])
					f[j][i] += 1 + f[j+1][i-1];
			}
		}
		printf("Case #%d: %d\n",cnt,f[0][n-1] % mo);
	}
	return 0;
}
