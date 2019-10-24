#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;
int n, ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	while (q.size()>1)
	{
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	cout << ans << endl;
}
