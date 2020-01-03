#include <cstdio>
#include <cstring>

const int N=1<<5,mo=1000000007;
typedef long long arr [N][N];

arr a,b,c,z;

void prepar()
{
	for (int j=1<<4;j<(1<<5);j++)
	{
		int k=(j&((1<<4)-1))<<1;
		if ((k&(1<<4))==0) a[j][k^(1<<4)]=1;
		else{
			for(int dep=0;dep<4;dep++){
				if ((k&(1<<dep))==0)
					a[j][k^(1<<dep)]=1;
			}
		}
	}
}

void fz(arr &x,arr &y)
{
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			x[i][j]=y[i][j];
}

void mult(arr x,arr y,int kk)
{
	memset(z,0,sizeof z);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++){
			for (int k=1;k<=N;k++){
				z[i][j]+=x[i][k]*y[k][j];
				z[i][j]%=mo;
			}
		}
	if (kk==1) fz(a,z);else fz(c,z);
}

void work(arr &a,long long k)
{
	bool flag=false;
	memset(c,0,sizeof c);
	while (k!=0) {
		if (k%2==1) if (!flag) {
			fz(c,a);
			flag=true;
		} else mult(c,a,2);
		mult(a,a,1);
		k=k>>1;
	}
	
}

int main()
{
	long long n;
	scanf("%lld",&n);
	prepar();
	work(a,n);
	printf("%lld\n",c[28][28]);
	return 0;
}
