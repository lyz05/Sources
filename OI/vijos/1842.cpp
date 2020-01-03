#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100005,mo = 99999997;
struct node
{
	int id,v;
} a[N],b[N];
int n,ans;
int c[N],p[N],h[N];

bool cmp(node A,node B) {return A.v<B.v;}
bool cmp1(node A,node B) {return A.id<B.id;}

int lowbit(int x)
{   
    return x & (-x);   
}  
void modify(int pos,int num)  
{  
    while (pos<=N) {  
        h[pos] += num;  
        pos += lowbit(pos);  
    }  
}  
int sum(int end)  
{  
    int sum=0;  
    while (end>0) {  
        sum += h[end];  
        end -= lowbit(end);  
    }  
    return sum;  
}  
  
void work()
{
	for (int i=1;i<=n;i ++)
	{
		modify(c[i],1);
		(ans += i-sum(c[i]))%=mo;
	}
}

int main()
{
	freopen("1842.in","r",stdin);
	//freopen("1842.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i].v),a[i].id = i;
	for (int i=1;i<=n;i ++) scanf("%d",&b[i].v),b[i].id = i;
	sort(a+1,a+1+n,cmp);sort(b+1,b+1+n,cmp);
	for (int i=1;i<=n;i ++) a[i].v = i,b[i].v = i;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i ++) p[b[i].v] = b[i].id;
	for (int i=1;i<=n;i ++) c[i] = p[a[i].v];
	work();
	printf("%d\n",ans);
	return 0;
}
