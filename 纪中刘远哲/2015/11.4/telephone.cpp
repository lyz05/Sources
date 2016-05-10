#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXW = 5000+5,MAXL = MAXW,N = 3000+5;
struct node
{int x,y,z,id;} W[MAXW],L[MAXL];

int n,w,l;
int h[N],ans[2][N];
bool flag;

bool cmp(node A,node B)
{return A.z<B.z;}

void prepar()
{
	flag = 0;
	memset(ans[1],0,sizeof ans[1]);
	for (int i=1;i<=n;i ++) h[i] = i; 
}

int gf(int x)
{
	if (x==h[x]) return x;
	else return h[x] = gf(h[x]);
}

bool link(int x,int y)
{
	int i = gf(x),j = gf(y);
	if (i==j) return 0;
	else 
	{
		h[i] = j;
		return 1;
	}
}

void work()
{
	ans[0][0] = 1e9+7;
	sort(W+1,W+1+w,cmp);
	sort(L+1,L+1+l,cmp);
	for (int i=1;i<=l;i ++)
	{
		int tot = 0;
		prepar();
		link(L[i].x,L[i].y);
		ans[1][0] = L[i].z;
		ans[1][n-1] = L[i].id;
		for (int j=1;j<=w;j ++)
		{
			if (link(W[j].x,W[j].y)) 
			{
				ans[1][0] += W[j].z;
				ans[1][++ tot] = W[j].id;
				if (tot==n-2) 
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag && ans[0][0]>ans[1][0])
		{
			memcpy(ans[0],ans[1],sizeof ans[1]);
		}
	}
}

int main()
{
	freopen("telephone.in","r",stdin);
	freopen("telephone.out","w",stdout);

	int x,y,z;
	scanf("%d%d%d",&n,&w,&l);
	for (int i=1;i<=w;i ++) 
	{
		scanf("%d%d%d",&x,&y,&z);
		W[i].x = x,W[i].y = y,W[i].z = z,W[i].id = i;
	}
	for (int i=1;i<=l;i ++)
	{
		scanf("%d%d%d",&x,&y,&z);
		L[i].x = x,L[i].y = y,L[i].z = z,L[i].id = i;
	}

	work();
	for (int i=0;i<=n-1;i ++) printf("%d\n",ans[0][i]);

	return 0;
}

