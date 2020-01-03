#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

const int N = 1e6+7;
int a[N],n,k;
list <int> q;


int main()
{
	cin >> n >> k;
	for (int i=1;i<=n;i ++) cin >> a[i];
	
	q.clear();
	for (int i=1;i<=k;i ++)
	{ 
		while (!q.empty() && q.back()>a[i]) q.pop_back();
		q.push_back(a[i]);
	} 
	cout << q.front() << " ";
	for (int i=2;i<=n-k+1;i ++)
	{
		int j = i+k-1;
		if (a[i-1]==q.front()) q.pop_front();
		while (!q.empty() && q.back()>a[j]) q.pop_back();
		q.push_back(a[j]);
		cout << q.front() << " ";
	} 
	cout << endl;
	
	q.clear(); 
	for (int i=1;i<=k;i ++)
	{ 
		while (!q.empty() && q.back()<a[i]) q.pop_back();
		q.push_back(a[i]);
	} 
	cout << q.front() << " ";
	for (int i=2;i<=n-k+1;i ++)
	{
		int j = i+k-1;
		if (a[i-1]==q.front()) q.pop_front();
		while (!q.empty() && q.back()<a[j]) q.pop_back();
		q.push_back(a[j]);
		cout << q.front() << " ";
	} 
	cout << endl;
	return 0;
}
