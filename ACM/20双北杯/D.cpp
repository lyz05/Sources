#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000+7;
int ans,n,m,T;
int a[N],b[N],c[N];

bool cmp(int x,int y){
    return x>y;
}

int main()
{
	freopen("D.in","r",stdin);
	//freopen(".out","w",stdout);
    cin >> T;
    for (int t=1;t<=T;t++)
    {
        ans = 0;
        cin >> n >> m;
        for (int i=1;i<=n;i ++) cin >> a[i];
        for (int i=1;i<=n;i ++) cin >> b[i];
        for (int i=1;i<=n;i ++) {
            int low,high;
            low = (b[i]-a[i]<=0)?0:b[i]-a[i];
            high = (b[i]-2*a[i]<=0)?0:b[i]-2*a[i];
            c[i] = low-high;
            ans += low;
        }
        sort(c+1,c+n+1,cmp);
        for (int i=1;i<=m;i ++)
            ans -= c[i];
        cout << "Case #" << t << ":"<< endl;
        cout << ans << endl;
    }
    
	return 0;
}
