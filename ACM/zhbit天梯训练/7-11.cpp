#include <bits/stdc++.h>
using namespace std;

const int N = 30+5;
int n,mid[N],pre[N],h[1<<25];

void bulid(int id,int midl,int midr,int prel,int prer)
{
	if (midl>midr || prel>prer) return;
	h[id] = pre[prel];
	for (int i=midl;i<=midr;i ++) 
		if (mid[i]==h[id]) 
		{
			bulid(id*2,midl,i-1,prel+1,prel+(i-midl));
			bulid(id*2+1,i+1,midr,prel+(i-midl)+1,prer);
		}
}

void find(int x)
{
	queue <int> q;
	q.push(x);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now==1) cout << h[now];
		else cout  << " " << h[now];
		if (h[now*2+1]) q.push(now*2+1);
		if (h[now*2]) q.push(now*2); 
	}
}

int main()
{
	freopen("7-11.in","r",stdin);
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> mid[i];
	for (int i=1;i<=n;i ++) cin >> pre[i];
	bulid(1,1,n,1,n);
	find(1);
	return 0;
} 
