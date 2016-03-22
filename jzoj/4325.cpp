#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 15;
int s[N];
int n,ans;

void dfs(int dep,int ret)
{
	if (ret>=ans) return;
	if (dep>14)
	{
		ans = ret;
		return;
	}
	if (!s[dep])
	{
		dfs(dep+1,ret);
		return;
	}
	if (s[dep]>=4)		
	{
		s[dep] -= 4;
		for (int i=dep+1;i<=14;i ++)
			for (int j=i;j<=14;j ++)
			{
				for (int k=1;k<=2;k ++)
					if ((s[i]>=k && s[j]>=k && i!=j) || 
						(s[i]>=2*k && i==j))
					{
						s[i] -= k,s[j] -= k;
						dfs(dep,ret+1);//4��2
						s[i] += k,s[j] += k;
					}
			}
		dfs(dep,ret+1);//ը��
		s[dep] += 4;
	}
	if (s[dep]>=3)
	{
		s[dep] -= 3;
		for (int i=dep+1;i<=14;i ++)
		{
			for (int k=1;k<=2;k ++)
				if (s[i]>=k)
				{
					s[i] -= k;
					dfs(dep,ret+1);//����һ��������
					s[i] += k;
				}
		}
		if (dep>2)
		{
			int r;
			for (r=dep+1;r<=14;r ++)
				if (s[r]<3) break;
			for (int i=dep+1;i<r;i ++)	//3˳��
			{
				s[i] -= 3;
				dfs(dep,ret+1);
			}
			for (int i=dep+1;i<r;i ++) s[i] += 3;
		}

		dfs(dep,ret+1);//3����
		s[dep] += 3;
	}
	if (s[dep]>=2)
	{
		s[dep] -= 2;
		if (dep>1)
			for (int i=dep+1;i<=14;i ++)
				if (s[i]>=3)
				{
					s[i] -= 3;
					dfs(dep,ret+1);//������
					if (s[i])
					{
						s[i] --;
						for (int j=dep+1;j<=14;j ++)
						{
							s[j] -= 2;
							dfs(dep,ret+1);
							//�Ĵ���
							s[j] += 2;
						}
						s[i] ++;
					}
					s[i]+=3;
				}
		if (dep>2)
		{
			int r;
			for (r = dep+1;r<=14;r ++)
				if (s[r]<2) break;
			r --;
			if (r-dep+1>=3)
			{
				s[dep+1] -= 2;
				for (int i=dep+2;i<=r;i ++)
				{
					s[i] -= 2;
					dfs(dep,ret+1);
				}
				for (int i=dep+1;i<=r;i ++) s[i] += 2;
			}
		}
		dfs(dep,ret+1);//������
		s[dep] += 2;
	}
	s[dep] --;
	for (int i=dep+1;i<=14;i ++) 
		if (s[i]>=3)
		{
			s[i] -= 3;
			dfs(dep,ret + 1);//����һ
			if (s[i])
			{
				s[i] --;
				for (int j=dep+1;j<=14;j ++)
					if (s[j])
					{
						s[j] --;
						dfs(dep,ret+1);//�Ĵ���
						s[j] ++;
					}
				s[i] ++;
			}
			s[i] += 3;
		}
	if (dep>2)
	{
		int r;
		for (r = dep+1;r<=14;r ++)
			if (!s[r]) break;
		r --;
		if (r-dep+1>=5)
		{
			for (int i=dep+1;i<=dep+3;i ++) s[i] --;
			for (int i=dep+4;i<=r;i ++)
			{
				s[i] --;
				dfs(dep,ret+1);	//��˳��
			}
			for (int i=dep+1;i<=r;i ++) s[i] ++;
		}
	}
	dfs(dep,ret+1);//������
	s[dep] ++;
}

int main()
{
	freopen("landlords.in","r",stdin);
	//freopen("landlords.out","w",stdout);

	int T;
	scanf("%d%d",&T,&n);
	while (T --)
	{
		memset(s,0,sizeof s);
		ans = n;
		for (int i=1;i<=n;i ++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x = (x==1)?14:x;
			x = (x==0)?1:x;
			s[x] ++;
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
