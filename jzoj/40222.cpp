#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char s1[50010],s[50010];
int next[50010],fi,len,n;

int main()
{
	freopen("4022.in","r",stdin);
	scanf("%s" , s1);
	n = len = strlen(s1);
	for (int i = 0 ; i < n ; i ++) s[i + 1] = s1[i] , next[i + 1] = i + 2;
	next[n] = -1 , fi = 1;
	for (int L = 1 ; L * 2 <= len ; L ++)
	{
		n=strlen(s1);
		while (1) 
		{
			if (L * 2 > len) break;
			int flag = 0 , x = fi , y = fi;
			for (int i = 1 ; i <= L ; i ++) y = next[y];
			while (!flag)
			{
				int p = 0;
				for (int i = x , j = y , step = 0; s[i] == s[j] ; i = next[i] , j = next[j])
				{
					step ++; 
					if (step == L) {flag = 1 ; break;}
					if (next[j] == -1) {p = 1; break;}
				}
				if (flag || p) break;
				x = next[x] , y = next[y];
				if (y == -1) break;
			}
			if (!flag || y == -1 || x == -1) break;
			int tx = x , ty = y;
			for (int i = 1 ; i < L ; i ++) tx = next[tx] , ty = next[ty];
			next[tx] = next[ty] , len -= L;
			/*for (int i = fi ; i != -1 ; i = next[i]) printf("%c" , s[i]);
			printf("\n");*/
		}
	}
	for (int i = fi ; i != -1 ; i = next[i]) printf("%c" , s[i]);
	return 0;
}
