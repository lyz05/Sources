#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> s1;
stack<char> s2;

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++)
	{
		int t;
		cin >> t;
		s1.push(t); 
	}
	for (int i=1;i<n;i ++)
	{
		char t;
		cin >> t;
		s2.push(t); 
	}
	while (!s1.empty() && !s2.empty()) {
		int y = s1.top();s1.pop();
		int x = s1.top();s1.pop();
		char z = s2.top();s2.pop();
		int ans = 0;
		if (z=='+') ans = x+y;
		if (z=='-') ans = x-y;
		if (z=='*') ans = x*y;
		if (z=='/') {
			if (y!=0)
				ans = x/y;
			else {
				printf("ERROR: %d/0",x);
				return 0;
			}
		}
		s1.push(ans);
	}
	cout << s1.top();
	return 0;
}
