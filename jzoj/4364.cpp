#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int mo = 10007,dir[]={2,3,5,7},N = 100000+5;
int a[N],b[N],f[N][3][3],mo1,mo2;
char s[N],n[N],m[N];
int ans;

int work(char s[])
{
	memset(a,0,sizeof a);memset(b,0,sizeof b);
	int len = strlen(s),now = 0,ret = 0;
	for (int i=1;i<=len;i ++) a[i] = s[len-i]-'0';
	a[1] += 2;
	for (int i=1;i<=len;i ++) a[i+1] += a[i]/10,a[i] %= 10;
	if (a[len+1]) len ++;

	for (int i=len;i>=1;i --)
	{
		now = now*10+a[i];
		b[i] = now/3;
		now %= 3;	
	}
	while (b[len]==0) len--;
	for (int i=len;i;i --) 
		ret = (ret*10+b[i])%mo;
	
	return ret;
}


int get(char s[])
{
	int n = 0,res = 0,ans = 0;
	n = strlen(s);
	for (int i=0;i<n;i ++) res += s[i]-'0';
	res = res%3;

	memset(f,0,sizeof f);
	f[0][0][1] = 1;
	//f[0][0][0] = f[0][0][2] = 1;
	for (int i=1;i<=n;i ++)
	{
		for (int type=0;type<4;type ++)
		for (int k=0;k<3;k ++)
		{
			int j =	 dir[type];
			(f[i][(j+k)%3][0] += f[i-1][k][0]+((j<(s[i-1]-'0'))?f[i-1][k][1]:0))%=mo;
			(f[i][(j+k)%3][1] += (j==(s[i-1]-'0'))?f[i-1][k][1]:0)%=mo;
			(f[i][(j+k)%3][2] += f[i-1][k][2]+((j>(s[i-1]-'0'))?f[i-1][k][1]:0))%=mo;
		}
	}

	for (int i=1;i<n;i ++) 
		for (int j=0;j<3;j++)
			(ans += f[i][res][j])%=mo;
	(ans += f[n][res][0]+f[n][res][1])%=mo;
	ans = work(s)-ans;
	return ans;
}

int getmo3(char s[])
{
	int len = strlen(s),ret = 0;
	for (int i=0;i<len;i ++) ret += s[i];
	return ret%3;
}

void dec(char s[],int x)
{
	memset(a,0,sizeof a);
	int len = strlen(s);
	for (int i=1;i<=len;i ++) a[i] = s[len-i]-'0';
	a[1] -= x;
	for (int i=1;i<=len;i ++) a[i+1] -= (a[i]<0),a[i]=(a[i]+10)%10;
	if (a[len]==0 && len>0) len --;
	if (len) 
		for (int i=len;i>=1;i --) 
			s[len-i] = a[i]+'0';
	s[len] = '\0';
}

int main()
{
	freopen("4364.in","r",stdin);
	//freopen("4364.out","w",stdout);

	scanf("%s%s",n,m);
	mo1 = getmo3(n);mo2 = getmo3(m);
	if (mo1>mo2) mo2 +=3;
	dec(m,mo2-mo1);
	if (strlen(m)==0) ans = get(n); else ans = (get(n)-get(m)+mo)%mo;
	printf("%d\n",ans);

	return 0;
}
