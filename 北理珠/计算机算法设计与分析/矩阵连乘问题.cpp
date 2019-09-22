#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 6;
int m[N+1][N+1],s[N+1][N+1];

void MatrixChain(int *p,int n)
{
	for (int i=1;i<=n;i ++) m[i][i] = 0;
	for (int r=2;r<=n;r ++)
		for (int i=1;i<=n-r+1;i ++)
		{
			int j = i+r-1;
			m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for (int k=i+1;k<j;k ++)
			{
				int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if (t<m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
}

void out()
{
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=N;j ++)
			cout << m[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=N;j ++)
			cout << s[i][j] << " ";
		cout << endl;
	}
}

void work(int l,int r)
{
	if (l==r)
	{
		return;
	}
	cout << l << " " << s[l][r] << " " << r << endl;
	work(l,s[l][r]);
	work(s[l][r]+1,r);
}
int main()
{
	int p[]={30,35,15,5,10,20,25};
	MatrixChain(p,N);
	out();
	cout << endl;
	work(1,N);
	return 0;
} 
