#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n,year;
bool judge(int year,int n)
{
	int p[10],cnt = 0;
	memset(p,0,sizeof p);
	if (year<1000) p[0] = 1;
	while (year)
	{
		int t = year%10;
		p[t] = 1;
		year/=10;
	}
	for (int i=0;i<10;i ++)
		if (p[i]) cnt ++;
	return cnt==n;
}
int main()
{
	scanf("%d%d",&year,&n);
	for (int cnt=0;;cnt ++,year ++)
	{
		if (judge(year,n)) 
		{
			printf("%d ",cnt);
			for (int i=1000;i>=10;i/=10) 
				if (year<i) printf("0");
			printf("%d",year);
			return 0;
		}
	}
	return 0;
} 
