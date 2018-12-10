#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;
char s[3][N];
bool flag;

int main()
{
	freopen("1010.in","r",stdin);
	while (scanf("%s %s",s[1],s[2]) != EOF)
	{
		if (strlen(s[1])!=strlen(s[2]))
		{
			printf("No\n");
			continue;
		}
		int len = strlen(s[1]);
		for (int i=0;i<len;i ++)
		{
			flag = 1;
			for (int j=0,k=i+1;j<len;j ++,k ++)
			{
				if (k==len) k=0;
				if (s[2][j]!=s[1][k])
				{
					flag = 0;
					break;
				}
			}
			if (flag) 
			{
				printf("Yes\n");
				break;
			}
		}
		if (!flag) printf("No\n");
	}
} 
