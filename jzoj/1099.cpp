#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N=26+5;
using namespace std;

char s[3][N];
int n,num[N],jw=0;
bool p[N];

void print()
{
	for (int i=1;i<=n;i++)
		printf("%d ",num[i]);
	printf("\n");
	exit(0);
}

int val(char x)
{
	return num[x-'A'+1];
}

bool check()
{
	bool jw=0;
	for (int i=n-1;i>=0;i--)
	{
		if ((val(s[0][i])<0) || (val(s[1][i])<0) || (val(s[2][i])<0)) {
			return 1;
		}
		int tmp=val(s[0][i])+val(s[1][i]);
		tmp+=jw;
		jw=tmp/n;
		tmp%=n;
		if (tmp==val(s[2][i])) continue;
			else return 0;
	}
	return 1;
}

void dfs(int dep);

void init(int j,int dep)
{
	if (j>2)
	{
		int ljw=jw;
		int tmp=val(s[0][dep])+val(s[1][dep])+jw;
		jw=tmp/n;
		tmp%=n;
		if (tmp==val(s[2][dep])) dfs(dep-1);
		jw=ljw;
		return;
	}
	int id=(s[j][dep]-'A'+1);
	if (num[id]==-1)
	{
		for (int i=n-1;i>=0;i--)
			if (!p[i])
			{
				p[i]=1;
				num[id]=i;
					init(j+1,dep);
				num[id]=-1;
				p[i]=0;
			}
	} else init(j+1,dep);

}

void dfs(int dep)
{
	if (dep<0)
	{
		print();
		return;
	}
	init(0,dep);
}

int main()
{
	freopen("1099.in","r",stdin);
	scanf("%d\n%s\n%s\n%s\n",&n,&s[0],&s[1],&s[2]);
	
	memset(num,255,sizeof num);
	memset(p,0,sizeof p);
	dfs(n-1);
	return 0;
}
