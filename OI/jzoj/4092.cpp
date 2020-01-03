#include <cstdio>

const int N=500000;
int f[N][1<<5];

int main()
{
	int n;
	scanf("%d",&n);
	int j=(1<<4)+(1<<3)+(1<<2);
	f[0][j]=1;
	for (int i=0;i<n;i++)
	{
		for (int j=1<<4;j<(1<<5);j++){
			int k=(j&((1<<4)-1))<<1;
			if ((k&(1<<4))==0) f[i+1][k^(1<<4)]+=f[i][j];
		       	else{
				for(int dep=0;dep<4;dep++){
					if ((k&(1<<dep))==0)
					f[i+1][k^(1<<dep)]+=f[i][j];
				}
			}
		}
	}
	//printf("%d\n",f[n][28]);
	for (int i=1;i<=n;i++) printf("%d\n",f[i][28]);
	return 0;
}
