#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 550;
vector<int> G[maxn];
int deepth[maxn],n;
 
void topsort(){
	priority_queue<int, vector<int>, greater<int> > que;
	int i,cnt = 0;
	for(i=1 ;i<=n ;i++){
		if(!deepth[i]){
			que.push(i);
			deepth[i] = -1;
		}
	}
	while(que.size()){
		int t = que.top();
		que.pop();
		for(i=0 ;i<G[t].size() ;i++){
			deepth[G[t][i]]--;
			if(!deepth[G[t][i]]){
				que.push(G[t][i]);
			}
		}
		if(cnt)
			printf(" ");
		printf("%d",t);
		cnt++;
	}
}
 
int main(){
	int m;
	while(scanf("%d%d",&n,&m) != EOF){
		int i,x,y;
		for(i=1 ;i<=n ;i++){
			G[i].clear();
		}
		memset(deepth,0,sizeof(deepth));
		for(i=0 ;i<m ;i++){
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
			deepth[y]++;
		}	
		topsort();
		printf("\n");
	}
	return 0;
}