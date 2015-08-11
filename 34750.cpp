#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int a[1000001],b[1000001],i,j,k,mid,m,n;
int main()
{
	freopen("3475.in","r",stdin);
	
	scanf("%d",&m);
	mid=m/2;
	k=-1;
	while (k!=0)
	{
		scanf("%d",&k);
		if (k==1)
		{
			n++;
			scanf("%d",&a[n]);
		}
		if (k==2)
		{
			if(n==0) printf("Error: the stack is empty! \n");
			    else 
			    {
			    	printf("%d\n",a[n]);
			    	a[n]=0;
			    	n--;
				}
		}
		if (k==3)
		{
			if(n<m) printf("Error: less than %d elements in the stack! \n",m);
			    else
			    {
			       for (i=n;i>=n-mid;i--) b[(n-i+(n-mid))]=a[i];
			       for (i=n;i>=n-mid;i--) a[i]=b[i];
				}
		}
	}
}
