#include<set>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10;
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,l,r) for(int i=l;i<=r;i++)

struct states{
    int A[N][N];
}now,load[N],tmp;
bool flag;
int n,v;
int tot[N<<1],ttot[N][N<<1];
int ans[N][4]; 

void init(){
    scanf("%d",&n);
    For(i,5){
        while(scanf("%d",&v),v){
            now.A[i][++now.A[i][0]]=v;
            tot[v]++;        
        }
    }
}

void fall(){
    int k;
    For(i,5)
      Rep(j,2,7)
        if(now.A[i][j]&&!now.A[i][j-1]){
            for(k=j-1;!now.A[i][k]&&k>=1;k--); ++k;
            swap(now.A[i][j],now.A[i][k]);
        }
}

void remark(){
    For(i,5)
      For(j,7)
        if(now.A[i][j]){
            if(now.A[i][j]==now.A[i][j+1]&&now.A[i][j]==now.A[i][j-1]) tmp.A[i][j]=tmp.A[i][j-1]=tmp.A[i][j+1]=1;
            if(now.A[i][j]==now.A[i+1][j]&&now.A[i][j]==now.A[i-1][j]) tmp.A[i][j]=tmp.A[i-1][j]=tmp.A[i+1][j]=1; 
        }
}

void clean(){
    remark();
    bool ref=false;
    For(i,5)
      For(j,7)
        if(tmp.A[i][j]){
            tmp.A[i][j]=0;
            tot[now.A[i][j]]--;
            now.A[i][j]=0;
            ref=true;
        }
    if(ref){
        fall();
        clean();
    }
}

void move(int i,int j,int g){
    swap(now.A[i][j],now.A[i+g][j]);
    fall();
    clean();
}

bool check(){
    int cnt=0;
    For(i,10) if(tot[i]) cnt+=tot[i];
    return (!cnt);
}

void dfs(int step){
    if(flag) return;
    if(step>n){
        flag=check();
        return;
    }
    load[step]=now;
    For(i,10) ttot[step][i]=tot[i];
    For(i,5)
      For(j,7)
        for(int k=1;k>=-1&&now.A[i][j];k-=2){
            if((k==-1&&now.A[i-1][j])||(now.A[i+k][j]==now.A[i][j])) continue;//tree-pruning
            ans[step][1]=i-1;ans[step][2]=j-1;ans[step][3]=k;
            move(i,j,k);
            dfs(step+1);
            if(flag) return;
            now=load[step];
            For(sb,10) tot[sb]=ttot[step][sb];
        }
}

int main(){
    init();
    dfs(1);
    if(flag)  
	    For(i,n) 
		    printf("%d %d %d\n",ans[i][1],ans[i][2],ans[i][3]);
    else      
	    puts("-1");
    return 0;
}
