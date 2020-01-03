#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5*2+2;
vector <int> h[N];
//int h[N][10];
int n,m;

void hash(int x,int id)
{
	int k = x % N;
	while (1)
	{
		if (h[k].empty()) 
		{
			h[k].push_back(x);
			h[k].push_back(id);
			return;
		} 
		if (h[k][0] == x)
		{
			h[k].push_back(id);
			return;
		}
		k = (k+1) % N;
	}
}
int geth(int x)
{
	int k = x % N;
	while (1)
	{
		if (h[k].empty()) 
		{
			return -1;
		}
		if (h[k][0] == x)
		{
			return k;
		}
		k = (k+1) % N;
	}
}

bool find(int id,int l,int r)
{
	if (id == -1) return 0;
	int st = 1,en = h[id].size() - 1;
	int mid,tmp;
	while (st<=en)
	{
		mid = (st+en) >> 1;
		tmp = h[id][mid];
		if (l<=tmp && tmp<=r) return 1;
		if (tmp<l) st = mid + 1; else en = mid - 1;
	}
	return 0;
}

int main()
{
	freopen("2939.in","r",stdin);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int x;
		scanf("%d",&x);
		hash(x,i);
	}
	/*
	for (int i=0;i<N;i ++)
		if (!h[i].empty()) {
			//sort(h[i].begin(),h[i].end());
			for (int j=1;j<h[i].size();j ++) printf("%d ",h[i][j]);
			printf("\n");
		}
	*/
	scanf("%d",&m);
	for (int i=1;i<=m;i ++)
	{
		int l,r,st;
		scanf("%d%d%d",&l,&r,&st);
		if (find(geth(st),l,r)) printf("1"); else printf("0");
	}
	printf("\n");
}
