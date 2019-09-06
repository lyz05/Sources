#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

LL gcd(LL x,LL y)
{
	if (y==0) return x; else return gcd(y,x%y);
}

void judge(LL &x,LL &a,LL &y,LL &b)
{
	LL g =gcd(x,a);
	x=x/g;
	a=a/g;
	g =gcd(y,b);
	y=y/g;
	b=b/g;
	g =gcd(a,b);
	x = x*b/g;
	y = y*a/g;
	
	a = a*b/g;
	b = a;
	//1/4 1/12 3/12 3/12
	if (x==y) cout << "="; 
	else if (x<y) cout << "<";
	else if (x>y) cout << ">";
}

int main()
{
	freopen("J.in","r",stdin);
	
	LL x,a,y,b;
	while (cin>>x>>a>>y>>b)
	{
		judge(x,a,y,b);
		cout << endl;
	}
	
	return 0;	
} 
