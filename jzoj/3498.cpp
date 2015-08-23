#include <cstdio>
#include <cstring>
#include <cmath>
#define pi M_PI
#define rad(x) x*pi/180
using namespace std;

const int N = 105 , M = 1005;
typedef double matrix[4][4];
struct node
{
	double x,y,angle;
	int type,time;
} a[M];
struct point
{
	double x,y;
} p[N];
int n,m,top,stack[M],end[M];
matrix H;
char ch;

void mul(matrix &a,matrix b)
{
	matrix c;
	memset(c,0,sizeof c);
	for (int k=1;k<=3;k++)
		for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++)
				c[i][j] += a[i][k]*b[k][j];
	memcpy(a,c,sizeof c);
}
void pow(matrix &a,int y)
{
	matrix c;
	memset(c,0,sizeof c);
	for (int i=1;i<=3;i ++) c[i][i]=1;
	while (y>0)
	{
		if (y & 1 == 1) mul(c,a);
		mul(a,a);
		y >>= 1;
	}
	memcpy(a,c,sizeof c);
}
void work(int st,int en)
{
	if (st>en) return;
	matrix F,G;
	memset(F,0,sizeof F);
	for (int i=1;i<=3;i++) F[i][i] = 1;
	for (int i=st;i<=en;i++)
	{
		memset(G,0,sizeof G);
		if (a[i].type==1)
		{
			G[1][1] = 1;
			G[2][2] = 1;
			G[3][1] = a[i].x;
			G[3][2] = a[i].y;
			G[3][3] = 1;
			mul(F,G);
		}
		if (a[i].type==2)
		{
			G[1][1] = a[i].x;
			G[2][2] = a[i].y;
			G[3][3] = 1;
			mul(F,G);
		}
		if (a[i].type==3)
		{
			a[i].angle = 360 - a[i].angle;
			double co=cos(rad(a[i].angle)),si=sin(rad(a[i].angle));
			G[1][1] = co;
			G[1][2] = si;
			G[2][1] = -si;
			G[2][2] = co;
			G[3][1] = si*a[i].y-co*a[i].x+a[i].x;
			G[3][2] = -co*a[i].y-si*a[i].x+a[i].y;
			G[3][3] = 1;
			mul(F,G);
		}
		if (a[i].type==4)
		{
			work(i+1,end[i]-1);
			pow(H,a[i].time);
			mul(F,H);
			i = end[i];
		}

	}
	memcpy(H,F,sizeof F);
}
int main()
{
	freopen("transform.in","r",stdin);
	//freopen("transform.out","w",stdout);
	scanf("%d\n",&n);
	for (int i=1;i<=n;i++) scanf("%lf%lf\n",&p[i].x,&p[i].y);
	while (scanf("%c",&ch) != EOF)
	{
		m ++;
		if (ch=='T') a[m].type = 1,scanf("rans(%lf,%lf)\n",&a[m].x,&a[m].y);
		if (ch=='S') a[m].type = 2,scanf("cale(%lf,%lf)\n",&a[m].x,&a[m].y);
		if (ch=='R') a[m].type = 3,scanf("otate(%lf,%lf,%lf)\n",&a[m].angle,&a[m].x,&a[m].y);
		if (ch=='L') a[m].type = 4,scanf("oop(%d)\n",&a[m].time);
		if (ch=='E') a[m].type = 5,scanf("nd\n");
	}

	int top = 0;
	for (int i=1;i<=m;i++)
	{
		if (a[i].type == 4) stack[++ top] = i;
		if (a[i].type == 5) end[stack[top --]] = i;
	}
	work(1,m);
	for (int i=1;i<=n;i++)
	{
		matrix F;
		memset(F,0,sizeof F);
		F[1][1] = p[i].x , F[1][2] = p[i].y , F[1][3] = 1;
		mul(F,H);
		printf("%.4lf %.4lf\n",F[1][1],F[1][2]);
	}
	return 0;
}
