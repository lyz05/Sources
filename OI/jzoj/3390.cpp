#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 55,M = 55;
int n,m,t1,t2,v,tot,ans;
double l,r,mid;
bool flag,p[2*N*M];
double len[N][M],time[N*M];
int kind[2*N*M],f[2*N*M],x[N],y[N];

double sqr(int x) {return (double)x*x;}

bool check(int x)
{
	if (x==0) return 1;			//û�б�ѡ��
	for (int i=1;i<=tot;i ++)		//ɨ��ÿ��ƥ���
	{
		if (!p[i] && time[i]+len[kind[i]][x]/v<=mid)
		{
			//�б���������ƥ��,������β��ҵݹ�·����û�г��Ըı��������
			p[i] = 1;
			if (check(f[i]))	//ƥ���û�й������߿����ڳ�λ��
			{
				f[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	freopen("3390.in","r",stdin);
	scanf("%d%d%d%d%d",&n,&m,&t1,&t2,&v);
	for (int i=1;i<=m;i ++) scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;i ++) 
	{
		int x1,y1;
		scanf("%d%d",&x1,&y1);
		for (int j=1;j<=m;j ++)
			len[i][j] = sqrt(sqr(x[j]-x1)+sqr(y[j]-y1));

	}
	l = 0,r = 1e8;
	while (r-l>1e-8)
	{
		mid = (l+r)/2;
		tot = 0;
		for (int i=1;i<=n;i ++)
		{
			ans = 0;
			double t = 0;
			while (t+t1/60+t2<=mid)
			{
				ans ++;
				tot ++;
				kind[tot] = i;
				time[tot] = ((double)t1/60)*ans+t2*(ans-1);
				t = t+t1/60+t2;
				if (tot==i*m) break;
			}
			if (t+t1/60<=mid && tot<i*m)
			{
				ans ++;
				tot ++;
				kind[tot] = i;
				time[tot] = ((double)t1/60)*ans+t2*(ans-1);
				t = t+t1/60+t2;
			}
		}
		bool flag;
		memset(f,0,sizeof f);
		for (int i=1;i<=m;i ++)		//��ÿһ���㶼����ƥ��
		{
			memset(p,0,sizeof p);	//��ձ������
			flag = check(i);
			if (!flag)
			{
				l = mid;
				break;
			}
		}
		if (flag) r = mid; 	
	}
	printf("%.6f",r);
	return 0;
}

