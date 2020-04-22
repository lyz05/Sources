#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n,a,b,c,ans;

int main()
{
	freopen("6.in","r",stdin);
	//freopen(".out","w",stdout);

    cin >> n;
    cin >> a >> b >> c;

    for (int i=1;i<=n;i ++)
        if (i%a!=0 && i%b!=0 && i%c!=0) 
            ans ++;
    cout << ans;
	return 0;
}
