#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 205,M = 100000005;
char p[N],s[M],m[5];
int next[N];

void getnext(char s[],int next[])
{
	int len = strlen(s);
	next[0] = -1;
	int k = -1,j = 0;
	while (j<len-1)
	{
		//p[k] 表示前缀,p[j] 表示后缀
		if (k==-1 || p[j]==p[k])
		{
			k ++,j ++,next[j] = k;
		} else	k = next[k];
		//沿着失配边走
	}
}

int kmpsearch(char s[],char p[])
{
	int i=0,j=0,slen=strlen(s),plen=strlen(p);
	while (i<slen && j<plen)
	{
		if (j==-1 || s[i]==p[j])
			i ++,j ++;
		else	j = next[j]; 
	}
	if (j==plen)
		return i-j;
	else	return -1;
}

int main()
{
	freopen("1005.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%s",p);
	for (int i=1,j=-1;j<M;i ++)
	{
		int k = i,len = -1;
		while (k)
		{
			m[++ len] = k % 10+'0';
			k /= 10;
		}
		for (int len = strlen(m)-1;len>=0;len --)
			s[++ j] = m[len];
	}
	//printf("%s\n",s);
	getnext(p,next);
	printf("%d\n",kmpsearch(s,p)+1);
	return 0;
}
