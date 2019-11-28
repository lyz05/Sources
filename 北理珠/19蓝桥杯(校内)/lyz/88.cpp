#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 100000+7;
int n,tot;
int a[N],s[N][2];
LL ans;

int main()
{
	//freopen("7.in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i];
	for (int i=1;i<=n;i ++)
	{
		for (int j=i-1;j>=1;j --)
			if (a[j]>a[i])
			{
				ans += i-j;
				break;
			}
	}
	cout << ans << endl;
	return 0;
}
