#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},st[4],en[4];
int ans;

int swap(int x)
{
	return x%10*10+x/10;
}

bool judge(int x)
{
	int year,month,day;
	year = x;
	month = x%100;
	day = x/100;
	month = swap(month);
	day = swap(day);
	if ((year%400==0)||(year%100!=0 && year%4==0)) a[2]=29;
		else a[2]=28;
	if (month>=1 && month<=12 && day<=a[month]&& day>=1)
	{
		if (year==st[0]){ 
			if (month>=st[1])
			{ 
				if (month==st[1] && day>=st[2]) return 1;
				if (month>st[1]) return 1;
			} 
		}
		if (year>st[0] && year<en[0]) return 1;
		if (year==en[0])
		{
			if (month<=en[1])
			{
				if (month==en[1] && day<=en[2]) return 1;
				if (month<en[1]) return 1;
			}
		}
		return 0;
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	int x = n / 10000,y = m / 10000;
	st[0]=x;st[1] = (n%10000)/100;st[2]=n%100;
	en[0]=y;en[1] = (m%10000)/100;en[2]=m%100;
	for (int i = x;i <= y;i ++)
	{
		if (judge(i)) ans ++;
	}
	printf("%d\n",ans);
}