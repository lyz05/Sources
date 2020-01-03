#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1000+5;
char s[26+5];
int a[26+5];
int n;

struct Node
{
	char s[100+5];
} ss[N];

bool cmp(Node A,Node B)
{
	int len = max(strlen(A.s),strlen(B.s));
	for (int i=0;i<len;i ++)
	{
		if (A.s[i]==B.s[i]) continue;
		if (A.s[i]=='\0') return 1;
		if (B.s[i]=='\0') return 0;
		return a[A.s[i]-'a']<a[B.s[i]-'a'];
	}
	return 0;
}

void init()
{
	for (int i=1;i<=26;i ++)
	{
		if (s[i]>='a' && s[i]<='z') a[s[i]-'a'] = i;
		//if (s[i]>='A' && s[i]<='Z') a[s[i]-'A'] = i;
	}
}

int main()
{
	//freopen("5.in","r",stdin);
	
	scanf("%d",&n);
	scanf("%s",s);
	init();
	for (int i=1;i<=n;i ++)	scanf("%s",ss[i].s);
	sort(ss+1,ss+1+n,cmp);
	for (int i=1;i<=n;i ++) printf("%s\n",ss[i].s);
	return 0;
} 