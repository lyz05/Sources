#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
const int N = 1e6+5 , mo = 1e9+7;
char s[N];
int mat[N],st[N];
LL l[N],r[N],up[N];
LL ans[N],sum;

int main()
{
	freopen("scare.in","r",stdin);//freopen("scare.out","w",stdout);
	int T;
	scanf("%d",&T);

	while (T--)
	{
		scanf("%s",s + 1);
		int len=strlen(s+1);
		sum = 0;
		int top = 0;
		for (int i=1;i<=len;i++)
			if (s[i]=='(') st[++ top] = i;
			else if (top)
			{
				mat[i] = st[top];
				mat[st[top]] = i;
				top --;
				up[mat[i]] = st[top];
			}
		
		for (int i=1;i<=len;i ++)
			if (mat[i] && s[i]==')') r[i] = r[mat[i]-1] + 1;
		for (int i=len;i>=1;i --)
			if (mat[i] && s[i]=='(') l[i] = l[mat[i]+1] + 1;

		for (int i=1;i<=len;i++)
			if (mat[i]) 
			{
				if (s[i]=='(')
					ans[i] = (l[i]*r[mat[i]]%mo+ans[up[i]])%mo;
				else ans[i] = ans[mat[i]];
				sum += ans[i]*i % mo;
			}
		printf("%lld\n",sum);

		for (int i=1;i<=len;i ++)
			l[i]=r[i]=up[i]=mat[i]=ans[i]=0;
	}
	return 0;
}
