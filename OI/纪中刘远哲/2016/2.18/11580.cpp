/* 
 * Problem: NOI2002 savage
 * Author: Guo Jiabao
 * Time: 2009.5.20 22:36
 * State: Solved
 * Memo: 线性同余方程
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
const int MAXN=16;
using namespace std;
int C[MAXN],P[MAXN],L[MAXN],N,M,S;

void init()
{
    //freopen("savage.in","r",stdin);
    //freopen("savage.out","w",stdout);
    scanf("%d",&N);
    S=N;
    for (int i=1;i<=N;i++)
    {
        scanf("%d%d%d",&C[i],&P[i],&L[i]);
        if (C[i] > S)
            S=C[i];
    }
}
int extend_gcd(int a,int b,int &x,int &y)
{
    if (!b)
    {
        x=1;y=0;
        return a;
    }
    else
    {
        int t,d;
        d=extend_gcd(b,a%b,x,y);
        t=x; x=y; y=t-(a/b)*y;
        return d;
    }
}
int mod_eq(int a,int b,int n)
{
    int d,x,y;
    d = extend_gcd(a,n,x,y);
    if (b%d) return -1;
    x = x * b / d % (n / d);
    x = ( x + n / d ) % ( n / d );
    return x;
}
bool legal()
{
    int i,j,x,a,b;
    for (i=1;i<N;i++)
    {
        for (j=i+1;j<=N;j++)
        {
            a=P[j]-P[i];b=C[i]-C[j];
            if (a<0 && b<0)
                a=-a,b=-b;
            if (a<0 && b>0)
                x=a,a=b,b=x;
            x=mod_eq(a,b,M);
            if (!(x==-1 || x>L[i] || x>L[j]))
                return false;
        }
    }
    return true;
}
void solve()
{
    for (M=S;!legal();M++);
    printf("%d\n",M);
}
int main()
{
	freopen("1158.in","r",stdin);
    init();
    solve();
    return 0;
}
