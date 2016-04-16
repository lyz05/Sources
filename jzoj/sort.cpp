#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100;
struct node
{
	int x,id;
	bool operator < (const node &B) const {return x>B.x;}
} a[N];
int n;

bool cmp(node A,node B)
{
	return A.x<B.x;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i].x), a[i].id = i;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i ++) printf("%d %d\n",a[i].id,a[i].x);

	return 0;
}
