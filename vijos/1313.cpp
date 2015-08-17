#include <cstdio>
#include <algorithm>

using namespace std;

const int N=32000+5,M=60+5;
int v[M],p[M],q[M],f[N];

int main()
{
	freopen("1313.in","r",stdin);	

	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&v[i],&p[i],&q[i]);
	for (int i=1;i<=m;i++)
	{
		int k1=0,k2=0;
		if (q[i]==0)
		{
			for (int j=i+1;j<=m;j++)
			{
				if (q[j]==i)
					if (k1==0)
						k1=j;
					else
					{
						k2=j;
						break;
					}
			}
			 
		
		for (int j=n;j>=v[i];j--)
		{
			f[j]=max(f[j],f[j-v[i]]+v[i]*p[i]);
			if ((j-v[i]-v[k1])>=0 && k1!=0)
				f[j]=max(f[j],f[j-v[i]-v[k1]]+v[i]*p[i]+v[k1]*p[k1]);
			if ((j-v[i]-v[k2])>=0 && k2!=0)
				f[j]=max(f[j],f[j-v[i]-v[k2]]+v[i]*p[i]+v[k2]*p[k2]);
			if ((j-v[i]-v[k1]-v[k2])>=0 && k1!=0 && k2!=0)
				f[j]=max(f[j],f[j-v[i]-v[k1]-v[k2]]+
				v[i]*p[i]+v[k1]*p[k1]+v[k2]*p[k2]);
		}
		}
	}
	printf("%d\n",f[n]);
	return 0;
}


