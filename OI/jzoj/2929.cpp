#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 50000+2 , mo = 2*N;
struct node
{
	int x,y;
} a[N],b[N];
int n,hash[mo+1][2];

bool cmp1(node a,node b)
{
	return a.x<b.x;
}

bool cmp2(node a,node b)
{
	return a.y<b.y;
}

bool enter(int x,int k,bool p)
{
	for (int y=x%mo;;y=(y+1)%mo)
	{
		if (hash[y][k]==x) return 1;
		if (hash[y][k]==-1)
		{	
			if (p) hash[y][k] = x;
			return 0;
		}
	}
}

int main()
{
	freopen("2929.in","r",stdin);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		//enter(a[i].x) , enter(a[i].y);
	}
	memcpy(b,a,sizeof a);
	memset(hash,-1,sizeof hash);
	
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+n,cmp2);
	a[n+1].x = a[n+1].y = 1e9;
	b[n+1].x = b[n+1].y = 1e9;
	for (int tot=1;tot<=3;tot ++)
	{
		int cnt = 0, maxx = 0 ,k = 0 ,kk = -1;
		for (int i=1;i<=n;i++)
		{
			if (!enter(a[i].x,0,0))
			{
				if (a[i].x == a[i+1].x) cnt ++;
				if (a[i].x != a[i+1].x)
			       	{
					cnt ++;
					if (cnt>maxx) 
					{
						maxx = cnt;
						k = a[i].x;
						kk = 0;
					}
					cnt = 0;
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (!enter(b[i].y,1,0))
			{
				if (b[i].y == b[i+1].y) cnt ++;
				if (b[i].y != b[i+1].y)
			       	{
					cnt ++;
					if (cnt>maxx) 
					{
						maxx = cnt;
						k = b[i].y;
						kk = 1;
					}
					cnt = 0;
				}
			}
		}
		
		enter(k,kk,1);
	}
	bool flag = true;
	for (int i=1;i<=n;i++)
		if (!enter(a[i].x,0,0) && !enter(a[i].y,1,0)) 
		{
			flag = 0;
			break;
		}
	if (flag) puts("1"); else puts("0");

	return 0;
}
