#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

char s[105];
int k,len,T,now;

int main()
{
	freopen("swap.in","r",stdin);
	//freopen("swap.out","w",stdout);

	scanf("%d",&T);
	while (T --)
	{
		scanf("%s %d",s,&k);
		len = strlen(s);
		for (int i=0;i<len;i ++)
		{
			now = i;
			for (int j=i;j<len && j-i<=k;j ++) 
				if (s[j]>s[now]) now = j;
			char t = s[now];
			for (int j=now;j>=i+1;j --) s[j] = s[j-1];
			s[i] = t;
			k -= now-i;
		}
		printf("%s\n",s);
	}

	return 0;
}
