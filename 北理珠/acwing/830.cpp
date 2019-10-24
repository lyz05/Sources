#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int N = 2e5+5;
int n,m,a[N];
stack<int> s;

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i]; 
	
	for (int i=1;i<=n;i ++)
	{
		while (!s.empty() && s.top()>=a[i]) s.pop();
		if (s.empty()) cout << "-1 ";
		else cout << s.top() << " ";
		s.push(a[i]);
	}
	return 0;
} 
