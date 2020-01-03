#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>

using namespace std;

typedef long long LL;

int P[35],A[35],B[35],N,p,tot,Ans;

bool cmp(int a,int b) {return a > b;}

long long sqr(int a) {return (long long)a * a % p;}

void Dfs(int Now,int Pre)
{
	if (Now > (N + 1) / 2)
	{
		for(int i = 1;i < N - i + 1;i ++) P[N - i + 1] = -P[i];
		for(int i = N;i >= 1;i --) if (P[i] < 0) P[i] += 10,P[i - 1] --;
		for(int i = 1;i <= N;i ++) A[i] = B[i] = P[i];
		sort(A + 1,A + N + 1),sort(B + 1,B + N + 1,cmp);
		int flag = 1;
		for(int i = N;i >= 1;i --)
		{
			B[i] -= A[i];if (B[i] < 0) B[i] += 10,B[i - 1] --;
			if (B[i] != P[i]) {flag = 0;break;}
		}
		if (flag)
		{
			int v = 0;
			for(int i = 1;i <= N;i ++) v = (v * 10LL + P[i]) % p;
			Ans = (Ans + sqr(v)) % p;
		}
	} else
		for(int i = Pre;i + 1;i --)
		{P[Now] = i;Dfs(Now + 1,i);}
}

int main()
{
	scanf("%d%d", &N, &p);
	Dfs(1,9);
	printf("%d\n",Ans);
	return 0;
}
