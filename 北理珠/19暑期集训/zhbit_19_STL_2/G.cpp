#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;
typedef long long LL;
priority_queue < LL,vector<LL>,greater<LL> > a;
set <LL> p;

int main()
{
	//freopen("C.in","r",stdin);
	a.push(1);
	for (int i=1;i<1500;i ++)
	{
		LL now = a.top();
		a.pop();
		if (!p.count(now*2)) a.push(now*2),p.insert(now*2);
		if (!p.count(now*3)) a.push(now*3),p.insert(now*3);
		if (!p.count(now*5)) a.push(now*5),p.insert(now*5);
	}
	cout << "The 1500'th ugly number is "<< a.top() <<".\n" << endl;
	return 0;
} 
