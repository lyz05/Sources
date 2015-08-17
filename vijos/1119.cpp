#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int oo=1e9-1,N=100*4+16;
double ans=oo,dis[N][N];
int s,t,A,B,V;
int x[N],y[N];

double sqr(double x)
{
	return x*x;
}

double getdis1(int x1,int y1,int x2,int y2)
{
	return sqr(x1-x2)+sqr(y1-y2);
}

double getdis(int x1,int y1,int x2,int y2)
{
	return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

void work()
{
	int tx[4],ty[4],v;
	double d[3];
	memset(dis,124,sizeof dis);
	for (int i=0;i<s;i++)
	{
		for (int j=0;j<3;j++) scanf("%d%d",&tx[j],&ty[j]);
		scanf("%d",&v);
		d[0]=getdis1(tx[0],ty[0],tx[1],ty[1]);
		d[1]=getdis1(tx[0],ty[0],tx[2],ty[2]);
		d[2]=getdis1(tx[1],ty[1],tx[2],ty[2]);
	        if(d[0] == d[1] + d[2])
		{
			swap(tx[0], tx[2]);
			swap(ty[0], ty[2]);
		}else 
			if(d[1] == d[0] + d[2])
		{
			swap(tx[0], tx[1]);
			swap(ty[0], ty[1]);
		}
		tx[3]=tx[1]+tx[2]-tx[0];
		ty[3]=ty[1]+ty[2]-ty[0];
		for (int j=0;j<4;j++)
		{
			x[i*4+j]=tx[j];
			y[i*4+j]=ty[j];
		}
		for (int j=0;j<4;j++)
			for (int k=j;k<4;k++)
				dis[4*i+j][4*i+k]=dis[4*i+k][4*i+j]
					=getdis(tx[j],ty[j],tx[k],ty[k])*v;
		for (int j=0;j<i;j++)
			for (int k=0;k<4;k++)
				for (int l=0;l<4;l++)
				{
					dis[4*j+k][4*i+l]=
						getdis(x[4*j+k],y[4*j+k],tx[l],ty[l])*V;
					dis[4*i+l][4*j+k]=dis[4*j+k][4*i+l];
				}
	}
	for (int k=0;k<4*s;k++)
		for (int i=0;i<4*s;i++)
			for (int j=i+1;j<4*s;j++)
			{
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			ans=min(ans,dis[4*(A-1)+i][4*(B-1)+j]);
		}
	}
}

int main()
{
	freopen("1119.in","r",stdin);
	scanf("%d%d%d%d",&s,&V,&A,&B);
	work();
	printf("%.2lf\n",ans);
	return 0;
}
