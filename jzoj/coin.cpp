#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long mo = 1000000007;

long long f[151][151],c[151][151];
int n,K,m;
char s1[151],s2[151];

void pre()
{
	memset(c , 0 , sizeof c);
	c[0][0] = 1;
	for (int i = 1 ; i <= 110 ; i ++) c[i][0] = 1;
	for (int i = 1 ; i <= 110 ; i ++)
		for (int j = 1 ; j <= i ; j ++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mo;
}

int main()
{

	pre();
	scanf("%d%d%d" , &n , &K , &m);
	scanf("%s" , s1);
	scanf("%s" , s2);
	int jishu = 0;
	for (int i = 0 ; i < n ; i ++) if (s1[i] != s2[i]) jishu ++;
	memset(f, 255 , sizeof f);
	f[jishu][0] = 1;
	
	for (int j = 0 ; j < K ; j ++)
	{
		for (int i = 0 ; i <= n ; i ++)
			if (f[i][j] != -1)
			{
				for (int k = 0; k <= min(i,m) ; k ++)
				{
					if (n - i < m - k) continue;
					if (f[i - k + m - k][j + 1] == -1) f[i - k + m - k][j + 1] = f[i][j] * c[i][k] % mo * c[n - i][m - k] % mo; 
						else f[i - k + m - k][j + 1] += f[i][j] * c[i][k] % mo * c[n - i][m - k] , f[i - k + m - k][j + 1] %= mo;
				}
			}
	}
	if (f[0][K] != -1) printf("%I64d" , f[0][K]); else printf("0");
	return 0;
}
