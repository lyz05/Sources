#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
char s[N];
int ans[10+5],maxx,T,tot;

int main()
{
	freopen("1004.in","r",stdin);
	scanf("%d",&T);
	while (T --)
	{
		memset(ans,0,sizeof ans);maxx = 0;
		scanf("%s",s);
		int len = strlen(s);
		for (int i=0;i<len;i ++) ans[s[i]-'0'] ++;
		for (int i=0;i<10;i ++) 
		{
			maxx = max(ans[i],maxx); 
			if (ans[i]>0) tot = i;	
		}
		for (int now=maxx;now;now--)
		{
			for (int i=0;i<=tot;i ++)
			{
				if (now>ans[i]) printf(" "); else printf("*");
			}
			printf("\n");
		}
		for (int i=0;i<=tot+1;i ++) printf("-");
		printf(">\n");
		for (int i=0;i<=tot;i ++) printf("%d",i);
		printf("\n\n");
	}
	return 0;
} 
