#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 1e6+2;
int a[N],len;
LL ans;
char s[N];
vector <int> h[N];

void work(int tot)
{
	int i=tot-2;
	for (int j=0;j<h[i].size();j ++)
	{
		int l=h[i][j],r=h[i][j]+i-1;
		if (s[l-1]=='(' && s[r+1]==')')
			h[tot].push_back(l-1);
	}
	for (int i=2;i<=tot;i += 2)
	{
		int j = tot-i;
		for (int k=0;k<h[i].size();k++)
		{
			int l=h[i][k],r	=l+i-1;
			for (int x=0;x<h[j].size();x++)
				if (r+1==h[j][x])
				{
					h[tot].push_back(l);
					break;
				} else if (r+1<h[j][x]) break;
		}
	}
}

int main()
{
	freopen("scare.in","r",stdin);//freopen("scare.out","w",stdout);
	
	int T;
	scanf("%d\n",&T);
	while (T --)
	{
		scanf("%s",s);
		len = strlen(s);
		for (int i=0;i<len-1;i++)
			if (s[i]=='(' && s[i+1]==')') 
				h[2].push_back(i);
		for (int i=4;i<=len;i += 2)
			work(i);
	}
	for (int i=1;i<=len;i++)
	{
		for (int j=0;j<h[i].size();j++)
			printf("%d ",h[i][j]);
		//if (!h[i].empty()) 
		printf("\n");
	}
	printf("%lld\n",ans);
	return 0;
}
