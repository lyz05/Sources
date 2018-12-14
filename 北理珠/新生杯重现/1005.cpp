#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000+5;
char s[N];
int ans[N];

int main()
{
	freopen("1005.in","r",stdin);
	while (gets(s) != NULL)
	{
		int len = strlen(s),tot = 0,cnt=0,now=0;
		for (int i=len-1;i>=0;i --,cnt ++)
		{
			if (cnt>4) 
			{
				ans[++ tot] = now;
				cnt -= 5;
				now = 0;
			}
			now += (s[i]-'0')<<cnt;
		}
		if (cnt)
		{
			ans[++ tot] = now;
			now = 0;	
		} 
		for (int i=tot;i;i --)
		{
			printf("%c",ans[i]<10?ans[i]+'0':ans[i]-10+'A'); 
		} 
		printf("\n");
	}
} 
