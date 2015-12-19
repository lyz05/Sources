#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXK = 10+1;
const char inf[] = {'J','O','I'};
char s[1<<(2*MAXK)];
int a[4],b[35];
int tmp,ans,K,len,k,now;

int main()
{
	freopen("logo.in","r",stdin);
	//freopen("logo.out","w",stdout);

	scanf("%d",&K);
	scanf("%s",s);
	len = (1<<(2*K));

	b[0] = 1;
	k = K-1;now = 0;tmp = 0;memset(a,0,sizeof a);
	for (int j=0;j!=(0-1+len)%len;j=(j+1)%len)
	{
		int L = (1<<(2*k));
		if (inf[now]!=s[j]) tmp ++;
		a[now]++;
		if (a[now]==L) 
			now ++,b[++ b[0]] = j;
		if (now==3) now = 0,k --,memset(a,0,sizeof a);
	}

	ans = tmp;
	for (int i=1;i<len;i ++)
	{
		for (int j=1,now = 2;j<=b[0];j ++,now=(now+1)%3)
		{
			b[j] = (b[j]+1)%len;
			if (j==1) 
			{
				if (s[(b[j]-1+len)%len]=='J')
					tmp ++;
				tmp --;
				continue;
			}
			if (j==b[0])
			{
				tmp ++;
				if (s[b[j]]=='I') tmp --;
				continue;
			}
			if (s[b[j]]==inf[(now+1)%3]) tmp ++;
			if (s[b[j]]==inf[now]) tmp --;
		}
		ans = min(ans, tmp);
	}
	printf("%d\n",ans);
	return 0;
}

