#include <cstdio>

using namespace std;

const int N = 100;

double dest,c,dy;
double dis[N],p[N];
double d,cy,ans,t,min;
int n,i,j,k;

void init()
{
	scanf("%lf%lf%lf%lf%d",&dest,&c,&dy,&p[0],&n);
	for (int i = 1;i <= n;i ++)
		scanf("%lf%lf",&dis[i],&p[i]);
}

void work()
{
	d = 0;		//旅行家的位置
	cy = 0;		//油量库存
	ans = 0;	//花费
	i = 0;		//到了第几个加油站
	while (d<dest)
	{
		if ((i == n) and (d+c*dy >= dest))
			//到达最后一个加油站,直接去终点 
		{
			ans += (dest-dis[i]-cy*dy)/dy*p[i];
			d = dest;
			break;
		}
		j = i+1;
		if (d+dy*c<dis[j]) break;
			//即使加满油也无法到达目的的
		min = 1e8;
		while (d+dy*c >= dis[j] && j<=n)
		{
			//在能去到下一个加油站下，判断最优加油站
			if (p[j]-p[i] < min)
			{
				min = p[j]-p[i];
				k = j;
			}
			j ++;
		}

		if (d+dy*c>=dest)
			//不经过最后一个加油站，就能到达终点
		{
			if (p[i] < p[k])
			//比较是到下个加油站，还是直接到终点
			{
				ans += (dest-dis[i]-cy*dy)/dy*p[i];
				d = dest;
				break;
			} else 
			{
				ans += (dis[k]-dis[i]-cy*dy)/dy*p[i];
				cy = 0;
				d = dis[k];
				i = k;
			}
		} else 
		{
			//不能去到终点，比较那个加油站更好
			if (p[i]<p[k])
			{
				ans += c*p[i];
				cy = c-(dis[k]-d)/dy;
				d = dis[k];
				i = k;
			} else 
			{
				ans += (dis[k]-d-cy*dy)/dy*p[i];
				cy = 0;
				d = dis[k];
				i = k;
			}
		}

	}
	
}

int main()
{
	//freopen("1253.in","r",stdin);
	init();
	work();
	if (d == dest) printf("%.2f",ans); else printf("-1\n");
}
