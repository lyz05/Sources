#include<cstdio>

using namespace std;

const int N=100000+5;
int num[N],cnt[N],n,m;

int main()
{
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",num+i);
	scanf("%d",&m);
	while (m--)
	{
		char ch;
		int a,b,c;
		scanf(" %c%d",&ch,&a);
		if (ch=='Q')
		{
			printf("%d %d\n",num[a],cnt[a]);

		} else 
		{
			scanf("%d%d",&b,&c);
			if (ch == 'A')
			{
				if (!c) continue;
				for (int i=a;i<=b;i++) 
				{
					num[i]+=c;
					cnt[i]++;
				}
			} else 
			{
				for (int i=a;i<=b;i++) 
				{
					if (num[i]<c) 
					{
						num[i]=c;
						cnt[i]++;
					}
					
				}
			}
		}
	}
	return 0;
}
