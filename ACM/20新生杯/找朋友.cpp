#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

map<int,int> a;
int T,n;

int main()
{
	cin >> T;
	while (T --) {
		a.clear();
		int ans = 0;
		cin >> n;
		for (int i=1;i<=n;i ++){
			int t;
			cin >> t;
			a[t] ++;
		}
		for(map<int,int>::iterator it=a.begin();it != a.end();it ++)
        {
        	int t = it -> second;
        	ans += t*(t-1)/2;
        }
        cout << ans << endl;
	}
	return 0;
 } 
