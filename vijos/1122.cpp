#include <cstdio>

using namespace std;

int f[16],n;

int main()
{
	f[0]=1;f[1]=1;
	for (int i=2;i<=15;i++)
		for (int j=0;j<i;j++)
			f[i] += f[j]*f[i-j-1];
	scanf("%d",&n);
	printf("%d\n",f[n]);
}
