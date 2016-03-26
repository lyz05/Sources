#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef unsigned arr[1030][1030];

int N, M, on, contain[20], order[1030];
arr UNIT, ARR1, ARR2, *NOW=&ARR1, *TMP=&ARR2;
bool A[20][20][30];
char s[1000], t[40];

void floodFill(int x, int &flag)
{
	flag|=1<<(x-1);
	for (int i=1;i<=N;i++)
		if (!(flag&(1<<(i-1))) && A[x][i][26])
			floodFill(i,flag);
}

inline void MUL(arr a, arr b, arr c)
{
	for (int i=1;i<=on;i++)
		for (int j=1;j<=on;j++)
			c[i][j]=0;
	for (int i=1;i<=on;i++)
		for (int j=1;j<=on;j++)
			for (int k=1;k<=on;k++)
				c[i][j]+=a[i][k]*b[k][j];
}

void POW(int exp)
{
	if (!exp) return;
	if (exp&1)
	{
		POW(exp-1);
		MUL(*NOW,UNIT,*TMP);
	} else
	{
		POW(exp>>1);
		MUL(*NOW,*NOW,*TMP);
	}
	swap(NOW,TMP);
}

int main()
{
	
	scanf("%s%d",s,&M);
	for (char *i=s,*j=t;*i;i++)
		if (*i=='[')
		{
			if (N) A[N][N+1][26]=true;
			for (i++;*i!=']';i++)
				A[N+1][N+2][*i-'a']=true;
			*(j++)=N/2+'0';
			N+=2;
		} else
			*(j++)=*i;
	for (char *i=t;*i;i++) if (*i=='*' || *i=='+')
	{
		char *j=i-1;
		int head(10), tail(-1);
		for (int cnt=0; *j==')' || cnt; j--)
			if (*j==')') cnt++; else
			if (*j=='(') cnt--; else
			if (*j!='*' && *j!='+')
				head=min(head,*j-'0'), tail=max(tail,*j-'0');
		A[tail*2+2][head*2+1][26]=true;
		//if (*i=='*')
		//	A[head*2+1][tail*2+2][26]=true;
	}
	for (int i=1;i<=N;i++)
		floodFill(i,contain[i]);
	for (int from=0;from<(1<<N);from++)
	{
		int all(0);
		for (int i=1;i<=N;i++) if (from&(1<<(i-1)))
			all|=contain[i];
		if (from==all)
			order[from]=++on;
	}
	for (int k=0;k<26;k++)
		for (int from=1;from<(1<<N);from++) if (order[from])
		{
			int next(0);
			for (int i=1;i<=N;i++) if (from&(1<<(i-1)))
				for (int j=1;j<=N;j++) if (A[i][j][k])
					next|=contain[j];
			UNIT[order[from]][order[next]]++;
		}
	for (int i=1;i<=on;i++)
		(*NOW)[i][i]=1;
	POW(M);
	unsigned ans(0);
	for (int i=1;i<(1<<N);i++)
		if (order[i] && i&(1<<(N-1)))
			ans+=(*NOW)[order[contain[1]]][order[i]];
	printf("%u\n",ans);
	return 0;
}
