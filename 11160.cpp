#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
#define PAU putchar(' ')
#define ENT putchar('\n')

using namespace std;
const int maxn=50010;
typedef long long LL;

int deq[maxn];LL C[maxn],S[maxn],dp[maxn];

double slope(int i,int j)
{return (dp[i]+S[i]*S[i]-dp[j]-S[j]*S[j])/(double)(S[i]-S[j]);}

inline int read(){
    int x=0,sig=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')sig=-1;ch=getchar();}
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return x*sig;
}

inline LL readl(){
    LL x=0,sig=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')sig=-1;ch=getchar();}
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return x*sig;
}

inline void write(LL x){
    if(x==0){putchar('0');return;}if(x<0)putchar('-'),x=-x;
    int len=0;LL buf[15];while(x)buf[len++]=x%10,x/=10;
    for(int i=len-1;i>=0;i--)putchar(buf[i]+'0');return;
}

int n,L;
void init(){
    n=read();
    L=read();
    C[0]=S[0]=0;
    for(int i=1;i<=n;i++){
	  C[i]=readl();
	  C[i]+=C[i-1];
	  S[i]=i+C[i];
     }
    return;
}
void work(){
    int s=0,e=0;
    dp[0]=deq[s]=0;
    for(int i=1;i<=n;i++)
    {
        LL m=S[i]-L-1;
        while(s<e && slope(deq[s+1],deq[s])<=(m<<1) ) ++s;
        int j=deq[s];dp[i]=dp[j]+(m-S[j])*(m-S[j]);
        while(s<e && slope(deq[e],deq[~-e])>=slope(i,deq[e]) ) --e;
        deq[++e]=i;
    }
    return;
}
void print()
{
    write(dp[n]);
    return;
}
int main()
{
	init();
	work();
	print();
	return 0;
}
