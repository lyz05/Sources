#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;

const int N = 2*1e5+7;
LL n,a[N],maxx,g,ans;

LL gcd(LL x,LL y)
{
	return y==0?x:gcd(y,x%y);
}

int main()
{
	//freopen("D.in","r",stdin);
	//freopen(".out","w",stdout);
	
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i],maxx = max(maxx,a[i]);
	for (int i=1;i<=n;i ++) 
		a[i] = maxx-a[i],g = gcd(a[i],g);
	for (int i=1;i<=n;i ++) ans += a[i]/g;
	cout << ans << " " << g << endl;
	return 0;
}
