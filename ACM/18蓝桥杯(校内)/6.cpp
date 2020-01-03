#include<cstdio>
using namespace std;

int n;

int main()
{
	//freopen("6.in","r",stdin);
	
	scanf("%d",&n);
	for (int i=2;i<n;i ++)
	{
		int t = n,cnt = 0;
		bool flag = 1;
		while (t)
		{
			if (t%i==1) cnt ++;
			if (cnt>2) 
			{
				flag = 0;
				break;
			}
			t /= i;
		}
		flag &= (cnt==2);
		if (flag) printf("%d\n",i);
	}
	
	return 0;
} 