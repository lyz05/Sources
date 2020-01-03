#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,P,ans;
int d[25],t[25];

struct Node{
	int mat[25][25];
}a,b,c;

void cheng(Node &a , Node &b ,int n , int m , int m1)
{
	Node c;
	memset(c.mat , 0 , sizeof c.mat);
	for (int i = 1 ; i <= n ; i ++)
		for (int j = 1 ; j <= m1 ; j ++)
			for (int k = 1 ; k <= m ; k ++)
				c.mat[i][j] += a.mat[i][k] * b.mat[k][j] , c.mat[i][j] %= P;
	
	for (int i = 1 ; i <= n ; i ++)
		for (int j = 1 ; j <= m1 ; j ++) a.mat[i][j] = c.mat[i][j];
}

void powq(Node &a , int x)
{
	if (x == 1) return;
	if (x & 1)
	{
		powq(a , x / 2);
		cheng(a , a , m , m , m);
		cheng(a , b , m , m , m);
	} else
	{
		powq(a , x / 2);
		cheng(a , a , m , m , m);
	}
}

int main()
{
	freopen("1115.in","r",stdin);
	scanf("%d%d%d" , &n , &m , &P);
	for (int i = 1 ; i <= m ; i ++) 
	{
		char ch; scanf("%c" , &ch);
		while (ch > '9' || ch <'0') scanf("%c" , &ch);
		t[i] = int(ch) - int('0');
	}
	for (int i = 0 ; i < m ; i ++)
	{
		for (int j = 0 , k = 1; j <= 9 ; j ++)
		{
			d[i + 1] = j;
			if (j == t[i + 1]) k = i + 1 + 1; else
			{
				k = 1;
				for (int k2 = 1 ; k2 <= i + 1 ; k2 ++)
				{
					int flag = 1;
					for (int k3 = k2 ; k3 <= i + 1 ; k3 ++) 
						if (d[k3] != t[k3 - k2 + 1]) flag = 0;
					if (flag) {k = i + 1 - k2 + 2; break;}
				}
			}
			b.mat[i + 1][k] += 1;
			c.mat[i + 1][k] += 1;
		}
		d[i + 1] = t[i + 1];
	}
	powq(c , n);
	memset(a.mat , 0 , sizeof a.mat); a.mat[1][1] = 1;
	cheng(a , c , 1 , m , m);
	ans = 0;
	for (int i = 1 ; i <= m ; i ++) ans += a.mat[1][i] , ans %= P;
	printf("%d" , ans);
	
	return 0;
}
