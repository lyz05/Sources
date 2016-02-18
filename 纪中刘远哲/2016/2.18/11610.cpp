/* 
 * Problem: NOI2002 robot
 * Author: Guo Jiabao
 * Time: 2009.5.19 17:43
 * State: Solved
 * Memo: Å·À­º¯Êý
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
const int MAXK=1001,MOD=10000;
using namespace std;
int P[MAXK],E[MAXK],F[MAXK],r1,r2,r3,M=1,K;
void init()
{
    freopen("1161.in","r",stdin);
    //freopen("robot.out","w",stdout);
    scanf("%d",&K);
    for (int i=1;i<=K;i++)
        scanf("%d%d",&P[i],&E[i]);
}
int QuickPower(int a,int k)
{
    if (k==1)
        return a % MOD;
    int t = QuickPower(a,k/2);
    t = t * t % MOD;
    if (k%2)
        t = t * a % MOD;
    return t;
}
void solve()
{
    int i,j,a=1;
    if (P[1]==2)
        a=2;
    F[0]=1;
    for (i=a;i<=K;i++)
        for (j=i-a+1;j>=1;j--)
            F[j] = ( F[j] + F[j-1] * (P[i]-1) ) % MOD;
    for (i=1;i<=K-a+1;i++)
        if (i%2)
            r2 = (r2 + F[i]) % MOD;
        else
            r1 = (r1 + F[i]) % MOD;
    for (i=1;i<=K;i++)
        M = ( M * QuickPower(P[i],E[i]) ) % MOD;
    r3 = (M + MOD + MOD + MOD - r1 - r2 - 1) % MOD;
}
int main()
{
    init();
    solve();
    printf("%d\n%d\n%d\n",r1,r2,r3);
    return 0;
}
