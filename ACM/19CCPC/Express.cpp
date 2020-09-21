#include <iostream>
#include <cstdio>
#include <cmath>

typedef long long LL;
using namespace std;

int main() {
    LL t, n, m, k;
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld%lld%lld",&n,&m,&k);
        LL minn = n,ans = 2*(k-1);
        for (int i=1;i<=m;i ++) {
            LL t;
            scanf("%lld", &t);
            minn = min(minn,t);
            ans += 2*abs(t-k);
        }
        if (minn<k) {
            ans -= 2*abs(minn-k);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
