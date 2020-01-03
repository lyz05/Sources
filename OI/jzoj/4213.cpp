#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1005,mo = 258280327;
struct bigint
{
	int a[500],len;
} f[N],m;
char s[500];

void add(bigint &a,bigint &b,bigint &c)
{
	c.len = max(a.len,b.len);
	for (int i = 1;i <= c.len;i ++)
	{
		c.a[i] += a.a[i]+b.a[i];
		c.a[i+1] += c.a[i] / 10;
		c.a[i] %= 10;
	}
	while (c.a[c.len+1])
	{	
		c.len ++;
		c.a[c.len+1] = c.a[c.len] / 10;
		c.a[c.len] %= 10; 
	}
}

bool min(bigint &a,bigint &b)
{
	if (a.len < b.len) return 1;
	if (a.len > b.len) return 0;
	for (int i = a.len;i;i --) 
		if (a.a[i] < b.a[i]) return 1; else 
		if (a.a[i] > b.a[i]) return 0;
	return 0;
}

void prepar()
{
	f[1].a[1] = f[1].len = 1;
	f[2] = f[1];
	for (int i = 3;i <= 1001; i ++) add(f[i-1],f[i-2],f[i]);
}

void work()
{
	memset(m.a,0,sizeof m.a);
	m.len = 0;
	int k;
	scanf("%d %s",&k,s);
	m.len = strlen(s);
	for (int i = m.len - 1; i>=0 ;i --)
	{
		m.a[m.len - i] = s[i] - '0';
	}
	m.a[1]	 ++;
	for (int i=1;i <= m.len; i ++) 
		m.a[i+1] += m.a[i] / 10 , m.a[i] %= 10;
	if (m.a[m.len+1]) m.len ++;
	int l=1, r=1001 , n;
	while (l <= r)
	{
		int mid = (l+r) >> 1;
		if (min(m,f[mid])) n = mid , r = mid - 1 ; else l = mid + 1;
	}
	n -= 2;
	m.a[1] --;
	for (int i=1;i<=f[n].len;i++)
	{
		m.a[i] -= f[n].a[i];
		if (m.a[i]<0) m.a[i] += 10 ,m.a[i+1] --;
	}
	while (m.len>1 && !m.a[m.len]) m.len --;
	int ans = 0;
	for (int i=m.len;i>0;i--)
	{
		ans = (ans * 10ll + m.a[i]) % mo;
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("4213.in","r",stdin);
	prepar();
	int T;
	scanf("%d\n",&T);
	while (T --) work();
}
