#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e4+7;
int n;

struct node
{
	int id,money,num;
} h[N];

bool cmp(node A,node B)
{
	if (A.money==B.money)
	{
		if (A.num==B.num) 
			return A.id<B.id;
		else
			return A.num>B.num;
	} else return A.money>B.money;
	return 0;
}

int main()
{
	//printf("%.2f",0);
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) h[i].id = i;
	for (int i=1;i<=n;i ++)
	{
		int T;
		scanf("%d",&T);
		for (int j=1;j<=T;j ++)
		{
			int id,p;
			scanf("%d%d",&id,&p);
			h[id].money += p;
			h[id].num ++;
			h[i].money -= p;
		}
	}
	sort(h+1,h+1+n,cmp);
	for (int i=1;i<=n;i ++)
	{
		printf("%d %.2f\n",h[i].id,1.0*h[i].money/100);
	}
	return 0;
} 
