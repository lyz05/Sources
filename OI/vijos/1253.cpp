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
	d = 0;		//���мҵ�λ��
	cy = 0;		//�������
	ans = 0;	//����
	i = 0;		//���˵ڼ�������վ
	while (d<dest)
	{
		if ((i == n) and (d+c*dy >= dest))
			//�������һ������վ,ֱ��ȥ�յ� 
		{
			ans += (dest-dis[i]-cy*dy)/dy*p[i];
			d = dest;
			break;
		}
		j = i+1;
		if (d+dy*c<dis[j]) break;
			//��ʹ������Ҳ�޷�����Ŀ�ĵ�
		min = 1e8;
		while (d+dy*c >= dis[j] && j<=n)
		{
			//����ȥ����һ������վ�£��ж����ż���վ
			if (p[j]-p[i] < min)
			{
				min = p[j]-p[i];
				k = j;
			}
			j ++;
		}

		if (d+dy*c>=dest)
			//���������һ������վ�����ܵ����յ�
		{
			if (p[i] < p[k])
			//�Ƚ��ǵ��¸�����վ������ֱ�ӵ��յ�
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
			//����ȥ���յ㣬�Ƚ��Ǹ�����վ����
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
