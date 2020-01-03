#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 300005, M = 4000005;
struct node
{
	node(){len = -1;}
	bool num;
	int len;
	int next,dep;
	int s[26];
} h[M];
int n,m,tot;
int a[N],f[N];
char s[N];
queue <int> Q;

void init()
{
	scanf("%d\n%s\n%d",&n,s,&m);
	for (int i=0;i<n;i ++) a[i] = s[i] - 'a';
	for (int i=1;i<=m;i ++)
	{
		scanf("%s",s);
		int len = strlen(s),now = 0;
		for (int j=0;j<len;j ++)
		{
			if (!h[now].s[s[j]-'a'])
				h[now].s[s[j]-'a'] = ++ tot;
			now = h[now].s[s[j]-'a'];
		}
		h[now].num = 1;
	}
	for (int i=0;i<26;i ++) if (h[0].s[i]) Q.push(h[0].s[i]);
	
	for (int x=Q.front();!Q.empty();x=Q.front())
	{
		Q.pop();
		for (int j=0;j<26;j ++)
			if (h[x].s[j])
			{
				int y = h[x].s[j];
				h[y].next = h[h[x].next].s[j];
				h[y].dep = h[x].dep + 1;
				Q.push(y);
			}
			else h[x].s[j] = h[h[x].next].s[j];
		if (h[x].num) h[x].len = h[x].dep;
		if (h[x].len<0) h[x].len = h[h[x].next].len;
	}
}

void work()
{
	for (int i=0,x=0;i<n;i ++)
	{
		x = h[x].s[a[i]];
		if (h[x].len>=0) ++ f[i-h[x].len],-- f[i+1];
	}
	int ans = 0;
	for (int i=0,sum = 0;i<n;i ++)
		sum += f[i],ans += !sum;
	printf("%d\n",ans);
}

int main()
{
	freopen("3172.in","r",stdin);
	//freopen(".out","w",stdout);

	init();
	work();

	return 0;
}
