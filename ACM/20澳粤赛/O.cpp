#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;
int dp[45],n;

int main()
{
	freopen("O.in","r",stdin);
	//freopen(".out","w",stdout);

    while (cin >> n) {
        int ans = 0;
        while (!q.empty()) q.pop();
        for (int i=1;i<=n;i ++) {
            int num;
            cin >> num;
            q.push(num);
        }
        while (q.size()>=2){
            int t1 = q.top();
            q.pop();
            int t2 = q.top();
            q.pop();
            ans += t1*t2;
            q.push(t1+t2);
        }
        cout << ans << endl;
    }

	return 0;
}
