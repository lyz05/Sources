#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 55;
int n,ans;
int h[N],flag[N];
struct node
{
	int x,y,z;
} a[N];

bool cmp(node A,node B)
{return A.z>B.z;}

int gf(int x)
{
	if (x!=h[x]) h[x] = gf(h[x]);
	return h[x];
}


bool link(int x,int y)
{
	int i = gf(x),j = gf(y);
	if (flag[i] && flag[j]) return 0;
	else 
	{
		h[i] = j;
		flag[j] |= flag[i];
	}
	return 1;
}

int main()
{
	freopen("1729.in","r",stdin);
	//freopen("1729.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<n;i ++) 
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	int x;
	while (scanf("%d",&x)!=EOF) flag[x] = 1;
	for (int i=1;i<=n;i ++) h[i] = i;

	sort(a+1,a+n,cmp);
	for (int i=1;i<n;i ++)
		if (!link(a[i].x,a[i].y)) 
			ans += a[i].z;
	printf("%d\n",ans);
	return 0;
}
