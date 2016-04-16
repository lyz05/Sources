#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int T,ans;
char s[200];

int work(int x)
{
	int i;
	for (i=1;x-i>=0 && s[x]==s[x-i];i ++);
	if (x-i<0) return 0;
	return work(x-i)+1;
}

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);

	scanf("%d",&T);
	for (int i=1;i<=T;i ++)
	{
		scanf("%s",s);
		ans = work(strlen(s)-1);
		if (s[strlen(s)-1]=='-') ans ++;
		printf("Case #%d: %d\n",i,ans);
	}

	return 0;
}
