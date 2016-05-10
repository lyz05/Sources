#include<cstdio>
#include<cstring>
#include<algorithm>
#include<list>
#include<cmath>

using namespace std;

const int N=1000+5;

struct node
{	
	int m,p,r;
	double d;
	//d距离m质量p吸引力r吸引半径
} a[N];

int n,x,y,d[N],m[N],ans;
list <int> s;
bool flag[N],v[N];

int sqr(int x)
{
	return x*x;
}

bool cmp(int x,int y)
{
	return a[x].d<a[y].d;
}

bool cmp1(int x,int y)
{
	return a[x].m<a[y].m;
}

double distance(int x1,int y1,int x2,int y2)
{
	return(sqrt(sqr(x1-x2)+sqr(y1-y2)));
}

void fillchar()
{
	for(int i=1;i<=n;i++)
       	{
		d[i]=i;
		m[i]=i;
	}
}

void bfs(node x)
{
	int head=1,tail=n,mid;
	while (head<=tail)
	{
		mid=(head+tail)>>1;
		if (x.r<a[d[mid]].d) tail=mid-1; else head=mid+1; 
	}
	mid=tail;
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=mid;i++)
	{
		if (v[d[i]]) continue;
		flag[d[i]]=true;
	}

	head=1;tail=n;
	while (head<=tail)
	{
		mid=(head+tail)>>1;
		if (x.p<a[m[mid]].m) tail=mid-1; else head=mid+1; 
	}
	mid=tail;
	for(int i=1;i<=mid;i++)
	{
		if (v[m[i]]) continue;
		if (flag[m[i]]) 
		{
			ans++;
			v[m[i]]=true;
			s.push_back(m[i]);
		}
	}

}

int main()
{
	freopen("1.in","r",stdin);
	scanf("%d %d %d %d %d",&x,&y,&a[0].p,&a[0].r,&n);
	for(int i=1;i<=n;i++)
	{
		int xx,yy;
		scanf("%d %d %d %d %d",&xx,&yy,&a[i].m,&a[i].p,&a[i].r);
		a[i].d=distance(x,y,xx,yy);
	}
	fillchar();
	sort(d+1,d+1+n,cmp);sort(m+1,m+1+n,cmp1);
	
	ans=0;
	s.push_back(0);
	while (!s.empty())
	{
		bfs(a[s.front()]);
		s.pop_front();
	}
	printf("%d\n",ans);
	return 0;
}
