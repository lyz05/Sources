#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<cstdlib>
#define pa pair<int,int>
#define inf 1000000000
#define linf 9000000000000000000LL
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int bin[20];
int n,t,ans[2050];
bool used[2050];
bool dfs(int x,int k)
{
	if(used[x])return 0;
	if(k==t)return 1;
	ans[k]=x&1;
	used[x]=1;
	if(dfs((x<<1)&(t-1),k+1))return 1;
	if(dfs((x<<1|1)&(t-1),k+1))return 1;
	used[x]=0;
	return 0;
}
int main()
{
	bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
	n=read();t=bin[n];
	printf("%d ",t);
	dfs(0,1);
	for(int i=1;i<n;i++)
		printf("0");
	for(int i=1;i<=t-n+1;i++)
		printf("%d",ans[i]);
	return 0;
}
