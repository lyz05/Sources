#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 3000+5;
struct node
{int x,y,id;} a[N],b[N],c[N];
int p[N];
int ans[N][2],tot,n;

bool cmp1(node A,node B){return A.x<B.x;}
bool cmp2(node A,node B){return A.y<B.y;}

int main()
{
	//freopen("family.in","r",stdin);
	//freopen("family.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
	{
		a[i].id = i;
		scanf("%d%d",&a[i].x,&a[i].y);
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	memcpy(b,a,sizeof a);memcpy(c,a,sizeof a);
	sort(b+1,b+1+n,cmp1);sort(c+1,c+1+n,cmp2);
	int tmp[2];
	ans[tot][0] = b[1].x,ans[tot][1] = c[1].y;
	for (int i=1;i<n;i ++)
	{
		tot ++;
		int k,cnt;
		for (int j=0;j<=i;j ++)
		{
			k=1,cnt=0;
			for (;k<=n && cnt<j;k ++) 
				if (!p[b[k].id]) cnt ++,p[b[k].id] = 1;
			k=1,cnt=0;
			for (;k<=n && cnt<i-j;k ++) 
				if (!p[c[k].id]) cnt ++,p[c[k].id] = 1;
			tmp[0] = tmp[1] = 0;
			for (k=1;k<=n && (!tmp[0] || !tmp[1]);k ++) 
			{
				if (!tmp[0] && !p[b[k].id]) tmp[0] = b[k].x;
				if (!tmp[1] && !p[c[k].id]) tmp[1] = c[k].y;
			}

			if (ans[tot][0]*ans[tot][1]<tmp[0]*tmp[1])
				ans[tot][0]=tmp[0],ans[tot][1]=tmp[1];

			memset(p,0,sizeof p);
		}
	}
	for (int i=tot;i>=0;i --) printf("%d %d\n",ans[i][0],ans[i][1]); 
	return 0;
}

