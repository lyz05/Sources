#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define pi 3.1415926
using namespace std;
double d[15][15],ans,dis,r[15];
int n,x[15],y[15],b[15];
int ok()
{
	for(int i=2;i<=n+1;i++)
		if(!b[i])return 0;
	return 1;
}

double mmin(double x,double y,double z,double p)
{
	double num=min(x,y);
	num=min(num,z);
	num=min(num,p);
	return num;
}

void dfs()
{
	if(ok()){dis=max(dis,ans);return;}
	for(int i=2;i<=n+1;i++)
	if(!b[i])
	{
		double minc=mmin(abs(x[i]-x[0]),
				         abs(x[i]-x[1]),
				         abs(y[i]-y[0]),
			             abs(y[i]-y[1]));
		for(int j=2;j<=n+1;j++)
			if(j!=i&&b[j])
			  minc=min(minc,d[i][j]-r[j]);
		if(minc<0)minc=0;
		b[i]=1;ans+=(minc*minc);
		r[i]=minc;
		dfs();
		b[i]=0;ans-=(minc*minc);r[i]=0;
	}
}

int main()
{
	freopen("1215.in","r",stdin);
	scanf("%d",&n);
	cin>>x[0]>>y[0]>>x[1]>>y[1];
	if(n==0)
	{
		ans=abs(x[0]-x[1])*abs(y[0]-y[1]);
		if(ans-(int)ans<0.5)ans=floor(ans);
		else ans=floor(ans)+1; 
		cout<<(int)ans;
		return 0;
	}
	for(int i=2;i<=n+1;i++)
		cin>>x[i]>>y[i];
	for(int j=2;j<=n+1;j++)
	 for(int i=2;i<=n+1;i++)
	  if(i!=j)
	 	d[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])
		 				+(y[i]-y[j])*(y[i]-y[j]));
	dfs();
	ans=abs(x[0]-x[1])*abs(y[0]-y[1])-pi*dis;
	if(ans-floor(ans)>=0.5)ans=floor(ans)+1;
	else ans=floor(ans); 
	cout<<ans; 
	return 0;
}
