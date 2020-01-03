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
		while (tot!=0 && s[tot][0]<a[i]) tot --;
		if (tot!=0)
		{
			ans += i-s[tot][1];
			//cout << i-s[tot][1] << " ";
		}
		s[++ tot][0] = a[i];
		s[tot][1] = i;
	}
	cout << ans;
	return 0;
}
