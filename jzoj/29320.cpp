#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#define ll long long
#define inf 100000000
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int now;
int n,K,tot;
bool ans[1000005];
void dfs(int x,int y)
{
    if(x==K&&y==tot)
    {
		now++;
		if(now==n)return;
    }
    if(y<tot&&now!=n)ans[x+y]=false,dfs(x,y+1);
    if(x<K&&now!=n)ans[x+y]=true,dfs(x+1,y);
}
int main()
{
    n=read();K=read();
    if(K==1)
    {
		printf("1");
		for(int i=1;i<n;i++)
			printf("0");
		puts("");
		return 0;
    }
    else 
    {
		ll sum=1,i=1;
		for(;sum*(i+K)/i<=n;i++)
			sum=sum*(i+K)/i;
		tot=i;now=sum;
		ans[0]=1;dfs(1,0);
		for(int i=0;i<tot+K;i++)printf("%d",ans[i]);
		puts("");
		return 0;
    }
    return 0;
}
