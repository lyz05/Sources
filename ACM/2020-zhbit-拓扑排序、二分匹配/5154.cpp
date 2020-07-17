#include<stdio.h>
#include<iostream>
#include<string.h>
#include <stdlib.h>
#include<math.h>
#include<algorithm>
#include <queue>
using namespace std;
int indegree[105];
struct Edge{
    int v,next;
}edge[10005];
int head[105];
int tot;
void addEdge(int u,int v,int &k){
    edge[k].v = v,edge[k].next = head[u],head[u] = k++;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(indegree,0,sizeof(indegree));
        memset(head,-1,sizeof(head));
        tot=0;
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(v,u,tot);
            indegree[u]++;
        }
        queue<int >q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            cnt++;
            q.pop();
            for(int k=head[u];k!=-1;k=edge[k].next){
                indegree[edge[k].v]--;
                if(!indegree[edge[k].v]) q.push(edge[k].v);
            }
        }
        if(cnt==n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/**
3 3
3 1
2 1
3 2
*/
