#include<cstdio>
using namespace std;
typedef long long LL;

const int N = 12;
LL now;
char a[N];
int n,tot;


int main()
{
	//freopen("1.in","r",stdin);
	//for (int m=1;m<=1000000;m ++)
	//{
	//n=m;
	scanf("%d",&n);
	tot = 0;
	while (n)
	{
		int now = n%26;
		if (now==0) now = 26;
		a[++ tot] = 'A'-1+now;
		n -= now;
		n /= 26;
	}
	for (int i=tot;i>=1;i --) printf("%c",a[i]);
	puts("");
	//}
	return 0;
} 

/*
1352+676+26
2*26*26+26*26+26

A  1
AA 26+1=27
AZ 26+26
ZZ 26*26+26
AAA 1*26*26+1*26+1=703
BZZ 2*26*26+26*26+26
BZZ 2*26^2+26*26^1+26*26^0
AAAA 1*26^3+1*26^2+1*26+1=18279
79...0
3...1
0...3

*/