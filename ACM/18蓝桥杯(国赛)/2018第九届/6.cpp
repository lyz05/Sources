#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000;
int n,a[N+5][N+5];

int gcd(int i,int j)
{
	if (j==0) return i;else return gcd(j,i%j);
}

int calc(int n)
{
	int cnt = 0;
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=n;j ++)
			cnt += a[i][j];
	return cnt;
}

int main()
{
	for (int i=1;i<=N;i ++)
		for (int j=1;j<=N;j ++)
		{
			a[i][j] = gcd(i,j);
			a[i][j] *= a[i][j]; 
		} 
	//cin >> n;
	for (int n=1;n<=1000;n ++)
	{
		printf("%d %d\n",n,calc(n));
	}
	return 0;
} 
