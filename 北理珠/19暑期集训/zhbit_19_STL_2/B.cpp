#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

using namespace std;
list <int> a;
int n;
bool flag = 0;

int main()
{
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	while (cin >> n)
	{
		if (n == 0) break;
		//if (flag) cout << endl;
		flag = 1;
		cout << "Discarded cards:";
		a.clear();
		for (int i=1;i<=n;i ++) a.push_back(i);
		while (a.size() > 1)
		{
			cout << " " << a.front();
			if (a.size()>2) cout << ",";
			a.pop_front();
			a.push_back(a.front());
			a.pop_front();
		}
		cout << endl << "Remaining card: " << a.front() << endl;
	}

	return 0;	
} 
