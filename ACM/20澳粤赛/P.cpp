#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n,ans,lnum,a,c;

int main()
{
	freopen("P.in", "r", stdin);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		c = 0;
		//构造当前数字为c
		for (int j = 0; j < 4; j++)
		{
			int t;
			cin >> t;
			if (t)
			{
				//记录今天开门的图书馆
				num++;
				c |= 1 << j;
			}
		}
		//今天有0个开门的图书馆
		if (num == 0)
		{
			lnum = 0;
			a = 0;
		}
		//今天有1个开门的图书馆
		else if (num == 1)
		{
			//判断昨天是否去过同样的图书馆
			if (a ^ c)
			{
				ans++;
				//记录今天开门的图书管为明天的昨天，并且记录只开了1个图书馆
				a = c;
				lnum = 1;
			}
			else
			{
				//去过同样图书馆
				lnum = 0;
				a = 0;
			}
		}
		else
		{
			//今天有好几个图书馆开门
			if (lnum == 1)
			{
				//昨天只有一个图书馆开门
				a = a ^ c;
				c = a;
				lnum = 0;
				//计算异或之后的今天开了多少家图书馆为明天的昨天
				while (c)
				{
					c -= c & (-c);
					lnum++;
				}
			}
			else
			{
				//多个选择的情况下不记录
				a = 0;
				lnum = 0;
			}
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
