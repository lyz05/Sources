#include <iostream>
#include <queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[200]={0};
int fz[200][200]={0};
int find(int x){
	int r=x;
	while(1){
		if(a[r]==0){
			return r;
		}
		r=a[r];
	}
//	return r;
}
void add(int n,int m){
	int x=find(n);
	int y=find(m);
	if(x!=y)
	  a[x]=y;
} 
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int q,w,e;
		cin>>q>>w>>e;
		if(e==1){
			add(q,w);
		}
		else{
			fz[q][w]=1;
			fz[w][q]=1;
		}
	}
	for(int i=0;i<k;i++){
		int q,w;
		cin>>q>>w;
		if(find(q)==find(w)&&fz[q][w]!=1){
			printf("No problem\n");
		}
		else if(find(q)==find(w)&&fz[q][w]==1){
			printf("OK but...\n");
		}
		else if(find(q)!=find(w)&&fz[q][w]==0){
			printf("OK\n");
		}
		else if(fz[q][w]==1&&find(q)!=find(w)){
			printf("No way\n");
		}
	}
	return 0;
}
