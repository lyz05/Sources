#include <bits/stdc++.h>
using namespace std;

double n,m,ans;

int main()
{
	cin >> n >> m;
	ans = 1.0*n/m/m;
	printf("%.1f\n",ans);
	if (ans>25) cout << "PANG" << endl;
	else cout << "Hai Xing" << endl;
	return 0;
}
