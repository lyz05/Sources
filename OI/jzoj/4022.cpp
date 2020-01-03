#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N=50000+5;
char s1[N],s[N];
int next[N],len,n;

int main()
{
	freopen("4022.in","r",stdin);freopen("4022.out","w",stdout);
	scanf("%s",&s1);
	n=len=strlen(s1);
	for (int i=1;i<=n;i++) s[i]=s1[i-1] , next[i]=i+1;
	
	next[n]=-1;

	int bj=len/2;
	if (n>=44000) bj=n/6;
	for (int L=1;L<=bj;L++)
	{
		int flag=0,x=1,y=1;
		for (int i = 1;i <= L;i ++) y=next[y];
		while (true)
		{
			bool p=false;
			flag=0;
			
			
			if (y==-1) break;
			for (int i=x,j=y,step=0;s[i]==s[j];i=next[i],j=next[j])
			{
				step++;
				if (step==L) {flag=true;break;}
				if (next[j]==-1) {p=true;break;}
			}

			if (p || x==-1 || y==-1) break;
			if (flag) 
			{
				//if (!flag || y=-1 || x=-1) continue;
				int tx=x,ty=y;
				for (int i=1;i<L;i++) tx=next[tx],ty=next[ty];
				next[tx]=next[ty],len-=L;
				y=x;
				for (int i = 1;i <= L;i ++) y=next[y];
			} else 
			{
				x = next[x];
				y = next[y];
			}

		}

	}

	for (int i=1;i!=-1;i=next[i]) printf("%c",s[i]);
	printf("\n");
	return 0;
}
