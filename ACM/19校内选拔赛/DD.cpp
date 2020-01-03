//求逆序对数 注意离散化
#include<iostream>
#include<cstring> 
#include<algorithm>
using namespace std;

const int maxn=1e5+10;
typedef pair<int,int > pir;

typedef long long ll;

int node[maxn];
int a[maxn];
pir b[maxn];//辅助数组
int n;

inline int lowbit(int x)
{
    return x&(-x);
}

void add(int a,int b)
{
    for(int i=a;i<=n;i+=lowbit(i)){
        node[i]+=b;
    }
}

ll sum(int n)//前缀和
{
    ll res=0;
    for(int i=n;i;i-=lowbit(i)){
        res+=node[i];
    }
    return res;
}

int main()
{
	freopen("D.in","r",stdin);
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    
    while (cin>>n)
    {
	    memset(node,0,sizeof node);
	    for(int i=1;i<=n;++i){
	        cin>>b[i].first;
	        b[i].second=i;
	    }
	    sort(b+1,b+n+1);
	    int k=1;
	    a[b[1].second]=k;//离散化后的值
	    for(int i=2;i<=n;++i){
	        if(b[i].first!=b[i-1].first) a[b[i].second]=++k;
	        else a[b[i].second]=k;
	    }
	    //for(int i=1;i<=n;++i) cout<<a[i]<<" ";
	    ll ans=0;
	//    for(int i=1;i<=n;++i){
	//        add(i,a[i]);
	//    }
	    for(int i=1;i<=n;++i){
	        ans+=sum(n)-sum(a[i]);
	        add(a[i],1);
	    }
	    cout<<ans<<endl;
	}
    return 0;
}

