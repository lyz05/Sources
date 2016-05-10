#include<cstdio>
#include<cmath>

using namespace std;

int t;

void work()
{
	int tmp;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int x,y,l,ans;
		scanf("%d %d %d",&x,&y,&l);
		if ((x%2==1) || (y%2==1)) 
		{
			printf("Poor MLG!\n");
			continue;
		} 
		l=(--l)*2;
		ans=x/l+y/l;
		tmp=x%l;
		l=l/2;
		for(int j=l;j>=1;j--)
		{
			ans+=tmp/j;
			tmp%=j;
		}
		printf("%d\n",ans);
	}

}

int main()
{
	work();
	return 0;
}
