#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

const int N = 500+2,M = 4*N;
int n,m,tot,A,B;
int a[N],e[N];
queue<int> q;
map<int,int> ans;

struct Node{
	int y,next;
} h[M];

void add(int x,int y)
{
	tot ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

int main()
{
	freopen("L3-1.in","r",stdin);
	cin >> n >> m;
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y);
	}
	cin >> A >> B;
	a[A] = 1;
	q.push(A);
	while (!q.empty()){
		int x = q.front();
		bool flag = 0;
		q.pop();
		for (int i=e[x];i;i=h[i].next){
			int y = h[i].y;
			a[y] += a[x];
			q.push(y);
			flag = 1;
		}
		if (!flag) ans[x] = 1;
	}
	cout << a[B] << " " << ((ans.size()==1 && ans[B]==1)?"Yes":"No");
	return 0;
}
