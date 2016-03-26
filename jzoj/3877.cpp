#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;

int xx[N], yy[N];
int x[N], y[N];
int n;

int ys()
{
	int c, r(0);
	while(c=getchar(), c<'0');
	r=c-'0';
	while(c=getchar(), c>='0')r=r*10+c-'0';
	return r;
}

int main()
{
	
	
	n = ys();
	for(int i=1, a, b; i<=n; i++)
	{
		a = ys(), b = ys();
		x[i] = a-b, y[i] = a+b;
		xx[i] = a, yy[i] = b;
	}
	
	sort(x+1, x+n+1), sort(y+1, y+n+1);
	
	int p = n / 2 + 1;
	
	double a = double(x[p]+y[p]) / 2.0;
	double b = double(y[p]-x[p]) / 2.0;
	
	printf("%.1lf %.1lf\n", a, b);
	
	double r(0);
	for(int i=1; i<=n; i++) r += max( fabs(a - xx[i]), fabs(b - yy[i]) );
	printf("%.6lf\n", r);
	
	return 0;
}
