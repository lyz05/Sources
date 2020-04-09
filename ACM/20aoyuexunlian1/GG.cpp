#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define lowbit(x) (x&(-x))
#define max(x,y) (x>=y?x:y)
#define min(x,y) (x<=y?x:y)
#define MAX 100000000000000000
#define MOD 1000000007
#define pi acos(-1.0)
#define ei exp(1)
#define PI 3.141592653589793238462
#define ios() ios::sync_with_stdio(false)
#define INF 1044266558
#define mem(a) (memset(a,0,sizeof(a)))
typedef long long ll;
const ll M=437893890380859375;
ll n;
ll quick_pow(ll x,ll y)
{
    ll ans=1;
    while(y)
    {
        if(y&1) ans*=x;
        x*=x;
        y>>=1;
    }
    return ans;
}
int main()
{
    freopen("G.in","r",stdin);
    while(scanf("%lld",&n)!=EOF)
    {
        if(n>=M) printf("15\n");
        else
        {
            for(int i=1;i<=14;i++)
            {
                if(quick_pow(i,i)<=n && n<quick_pow(i+1,i+1))
                {
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
