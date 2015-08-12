#include <cstdio>
#include <algorithm>

using namespace std;

const char list[3]={'T','L','R'},N = 30+2;
int n;
long long mi[N];

char get(char x,char y)
{
	for (int i=0;i<=2;i ++)
		if (list[i]!=x && list[i]!=y) return(list[i]);
	return ' ';
}

long long work(int m,char s[N],char c)
{
	long long v = 0;
	for (int i = m+1;i <= n;i ++)
		if (s[i]!=c) v = v + mi[i];
	return v;
}

int main()
{
	freopen("tri.in","r",stdin);
	freopen("tri.out","w",stdout);

	char s1[N],s2[N];
	scanf("%d",&n);
	scanf("%s\n%s",s1,s2);

	mi[n]=1;
	for (int i=n-1;i>=1;i --)
		mi[i]=mi[i+1]*2;
	if (s1==s2) printf("0"); else 
	{
		int m=1;
		while (s1[m]==s2[m]) m ++;
		if (m == n-1) printf("1"); else
		{
			char c = get(s1[m],s2[m]);
			long long v1 = work(m,s1,s2[m])+1+work(m,s2,s1[m]);
			long long v2 = work(m,s1,c)+work(m,s2,c)+mi[m]+1;
			long long v = min(v1,v2);
			printf("%lld",v);
		}
	}
	return 0;
}

