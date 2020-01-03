#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

char s[100+10];
int cnt[26];

bool ss(int x)
{
	if (x<=1) return 0;
	for (int i=2;i<=trunc(sqrt(x));i++)
	{
		if (x%i==0) return 0;
	}
	return 1;
}

int main()
{
	int maxn=0,minn=1e8;
	scanf("%s",&s);
	for (int i=0;i<strlen(s);i++)
	{
		int tmp=(int) s[i]-97;
		cnt[tmp]++;
	}
	for (int i=0;i<26;i++)
	{
		maxn=max(cnt[i],maxn);
		if (cnt[i]!=0) minn=min(cnt[i],minn);
	}
	if (ss(maxn-minn)) 
	{
		printf("Lucky Word\n%d\n",maxn-minn);
	} else printf("No Answer\n0\n");
}
