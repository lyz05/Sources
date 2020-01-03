#include <cstdio>

int main()
{
	int l,r,ans=0;
	scanf("%d%d",&l,&r);
	for (int x=l;x<=r;x++)
	{
		int xx=x;
		while (xx!=0) 
		{
			if (xx%10==2) ans ++;
			xx/=10;
		}
	}
	printf("%d\n",ans);
}
