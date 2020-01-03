#include<cstdio> 
#include<cstring> 
#include<algorithm> 
#define N 10005 
using namespace std; 
 
struct Edge{ 
    int u,v,val; 
    friend bool operator<(const Edge&a,const Edge&b){ 
        return a.val>b.val; 
    } 
}arr[N*10]; 
 
int f[N],rank[N],vis[N],n,m; 
 
void init(){ 
    for(int i=0; i<=n; ++i) 
        f[i]=i, rank[i]=0; 
} 
int find(int x){ 
    int i,j=x; 
    while(j!=f[j]) j=f[j]; 
    while(x!=j){ i=f[x]; f[x]=j; x=i; } 
    return j; 
} 
 
void Union(int x,int y){ 
    int a=find(x),b=find(y); 
    if(a==b) return ; 
    if(rank[a]>rank[b]) 
        f[b]=a; 
    else{ 
        if(rank[a]==rank[b]) 
            ++rank[b]; 
        f[a]=b; 
    } 
} 
 
 
int main(){
       //freopen("1030.in","r",stdin);	
    while(~scanf("%d%d",&n,&m)){ 
        if(!n&&!m)break; 
        for(int i=0; i<m; ++i) 
            scanf("%d%d%d",&arr[i].u,&arr[i].v,&arr[i].val); 
        init(); 
        sort(arr,arr+m); 
        memset(vis, 0, sizeof(vis)); 
        long long ans=0; 
        for(int i=0; i<m; ++i){ 
            int a=find(arr[i].u), b=find(arr[i].v); 
            if(a!=b){ 
                if(vis[a]&&vis[b]) continue;//两个都有环了 
                if(vis[a]||vis[b]) vis[a]=vis[b]=1; 
                ans += arr[i].val; 
                Union(a,b); 
            } 
            else if(!vis[a]){ // 虽然是同一棵数，但是还没有环 
                Union(a,b); 
                vis[a] = 1; 
                ans+=arr[i].val; 
            } 
        }  
         
        printf("%lld\n", ans); 
    } 
    return 0; 
} 
