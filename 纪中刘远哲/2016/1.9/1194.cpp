#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 55;
struct point
{
	point(double a=0,double b=0){x=a,y=b;}
	double x,y;
} P[N];
typedef point vector;
point operator + (point A,point B) {return point(A.x+B.x,A.y+B.y);}
point operator - (point A,point B) {return point(A.x-B.x,A.y-B.y);}
double cross(vector A,vector B) {return A.x*B.y - A.y*B.x;}
double area2(point A,point B,point C) {return cross(B-A,C-A);}
double sqr(double x) {return x*x;}
int n;
double f[N][N];

bool cmp(point A,point B)
{
	point C;
	return area2(C,A,B)>0;
}

int main()
{
	freopen("1194.in","r",stdin);
	//freopen("1194.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		P[i] = point(x,y);		
	}
	sort(P+1,P+1+n,cmp);
	
	double avr = 0,ans = 0;
	for (int i=2;i<=n-1;i ++)
	{
		f[i][i+1] = sqr(area2(P[1],P[i],P[i+1])/2);
		avr += area2(P[1],P[i],P[i+1])/2;
	}
	//printf("%f\n",avr);
	avr /= n-2;
	for (int l=2;l<=n-2;l ++)
	for (int i=2;i<=n-l;i ++)
	{
		//f[i][i+l] = max(f[i][i+k]+f[i+k][i+l])
		for (int k=i+1;k<i+l;k ++)
			f[i][i+l] = max(f[i][i+l],f[i][k]+f[k][i+l]);
	}
	ans = f[2][n]/(n-2)-avr;
	printf("%f",ans);
	//for (int i=1;i<=n;i ++) printf("%f %f\n",P[i].x,P[i].y);
	return 0;
}
