#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;

const int N = 25000+5,MP = 58000,M = 5875,yw = 100;
int T,tot;
int pri[M];
bool p[MP];
//bitset <MP> p;
char s[N];
short ans[M][N],n[N];

void mul(short c[],short a[],int b)
{
	int next = 0;
	for (int i=1;i<=a[0];i ++)
	{
		int t = (int)b*a[i]+next;
		c[i] = t%yw;
		c[0] = i;
		next = t/yw;
	}
	for (int i=a[0]+1;next;i ++)
	{
		c[i] = next%yw;
		c[0] = i;
		next /= yw;
	}
}

void prepare()
{
	for (int i=2;i<=MP;i ++)
	{
		if (!p[i])
		{
			pri[++ tot] = i;
			for (int j=2;i*j<=MP;j ++) p[i*j] = 1;	
		}
	}
	ans[0][0]=ans[0][1]=1;
	for (int i=1;i<=tot;i ++) 
		mul(ans[i],ans[i-1],pri[i]);
}

bool judge(short s1[],short s2[]) //s1<=s2
{
	int len1 = s1[0],len2 = s2[0];
	if (len1<len2) return 1;
	if (len1>len2) return 0;
	for (int i=len1;i;i --)
		if (s1[i]>s2[i]) return 0;
	return 1;
}

int half()
{
	int l = 1,r = tot,mid,ret = -1;
	while (l<=r)
	{
		mid = (l+r)>>1;
		if (judge(ans[mid],n))	//mid<=s
		{
			ret = mid;
			l = mid+1;
		} else r = mid-1;
	}
	return ret;
}

int main()
{
	freopen("3389.in","r",stdin);
	//freopen("3389.out","w",stdout);

	prepare();
	scanf("%d\n",&T);
	while (T --)
	{
		scanf("%s\n",s);
		//n[0] = strlen(s);
		memset(n,0,sizeof n);
		int j = 1,k = 1;
		for (int i=strlen(s)-1;i>=0;i --)
		{
			if (n[j]/(yw/10)) j ++,k=1;
			n[j]=(s[i]-'0')*k+n[j];
			k = k*10;
			n[0] = j;
		}
		
		k = half();
		if (k==-1) {puts("0");continue;}
		for (int i=ans[k][0];i;i --) 
		{
			for (int j=1;i!=ans[k][0]&&j<yw;j*=10)
			{
				if (ans[k][i]/j==0) 
					printf("0");	
			}
			printf("%d",ans[k][i]);
		}
		puts("");
	}

	return 0;
}
