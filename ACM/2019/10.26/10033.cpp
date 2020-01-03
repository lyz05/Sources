#include <cstdio>
#include <iostream>
#include <list>
using namespace std;
typedef long long LL;
const int N = 10000+5;
int n,ans,a[N];
string s;
list <int> q;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("10033.out","w",stdout);
	
	while (cin >> n && n)
	{
		for (int i=1;i<=n;i ++) cin >> a[i];
		q.clear();
		cin >> s;
		for (int k=0,i=0,j=0;k<s.length();k ++)
		{
			if (s[k] == 'm') 
			{
				j ++;
				while (!q.empty() && q.back()<a[j]) q.pop_back();
				q.push_back(a[j]);
			}
			else 
			{
				i ++;
				if (a[i] == q.front()) q.pop_front();
			}
			if (!q.empty()) cout << q.front() ; else cout << "0";
			cout << ((k+1<s.length())?" ":"");
		}
		cout << endl;
	}
	return 0;
}

//5
//1 2 4

//13
//1 2 4 8 
