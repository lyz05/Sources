#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;


const int N = 25000+5,MP = 58000,M = 5875,TT = 105;
int T,tot;
int pri[M];
bool p[MP];
//bitset <MP> p;
char s[N];
int ans[2][N],AA[TT][N];
struct node
{
	int a[N],id,ans[N];
} Q[TT];

void mul(int c[],int a[],int b)
{
	int next = 0;
	for (int i=1;i<=a[0];i ++)
	{
		int t = b*a[i]+next;
		c[i] = t%10;
		c[0] = i;
		next = t/10;
	}
	for (int i=a[0]+1;next;i ++)
	{
		c[i] = next%10;
		c[0] = i;
		next /= 10;
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

}

bool cmp(node A,node B) //s1<=s2
{
	int len1 = A.a[0],len2 = B.a[0];
	if (len1<len2) return 1;
	if (len1>len2) return 0;
	for (int i=len1;i;i --)
		if (A.a[i]>B.a[i]) return 0;
	return 1;
}
bool cmp1(node A,node B)
{
	return A.id<B.id;
}

bool judge(int A[],node B) //s1<=s2
{
	int len1 = A[0],len2 = B.a[0];
	if (len1<len2) return 1;
	if (len1>len2) return 0;
	for (int i=len1;i;i --)
		if (A[i]>B.a[i]) return 0;
	return 1;
}
int main()
{
	freopen("3389.in","r",stdin);
	//freopen("3389.out","w",stdout);

	prepare();
	scanf("%d\n",&T);
	for (int num=1;num<=T;num ++)
	{
		scanf("%s\n",s);
		Q[num].id = num;
		Q[num].a[0] = strlen(s);
		for (int i=Q[num].a[0],j=0;i>=1;i --,j ++) 
			Q[num].a[i] = s[j]-'0';
	}
	sort(Q+1,Q+1+T,cmp);
	int p=1,q=0,i=1;
	ans[0][0]=ans[0][1]=1;
	for (int num=1;num<=T;num ++)
	{
		if (Q[num].a[0]==1 && Q[num].a[1]<=1) 
		{
			Q[num].ans[0] = 1,Q[num].ans[1] = 0;
			continue;
		}
		for (;judge(ans[q],Q[num]);p^=1,q^=1)
		       mul(ans[p],ans[q],pri[i]),i ++;		
		int k = p;
		memcpy(Q[num].ans,ans[k],sizeof ans[k]);
	}
	sort(Q+1,Q+1+T,cmp1);
	for (int k=1;k<=T;k ++)
	{
		for (int i=Q[k].ans[0];i;i --) printf("%d",Q[k].ans[i]);
		puts("");
	}
	return 0;
}

