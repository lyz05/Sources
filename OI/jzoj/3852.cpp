#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define maxm 100100
#define maxn 1000
#define maxk 680
struct edges{
	int to,next;double dist;
}edge[maxm];
int num,next[maxn];
int addedge(int x,int y,double z) {
	edge[++num]=(edges){y,next[x],z};next[x]=num;
	return 0;
}
double dist[maxn];
int f[maxn];
queue<int> q;
int sum[maxn];
int spfa(int x,double y){
	for (int i=1;i<=maxk;i++) dist[i]=0;
	for (int i=1;i<=maxk;i++) sum[i]=0;
	while (!q.empty()) q.pop();
	q.push(x);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		f[u]=0;
		for (int i=next[u];i;i=edge[i].next){
			if (dist[edge[i].to]<edge[i].dist+dist[u]-y) {
				dist[edge[i].to]=edge[i].dist+dist[u]-y;
				if (f[edge[i].to]!=x) {
					q.push(edge[i].to);
					f[edge[i].to]=x;
					sum[edge[i].to]++;
					if (sum[edge[i].to]>maxk) return 1;
				}
			}
		}
	}
	return 0;
}
bool check(double x) {
	memset(f,0,sizeof(f));
	for (int i=1;i<=maxk;i++) {
		if (spfa(i,x)) return 1;
	}
//	printf("%lf\n",x);
	return 0;
} 
int dfs(int x,int y,bool z){
//	printf("%d\n",x);
	if (x==y&&z) return 1;
	if (f[x]==y) return 0;
	bool flag=0;
	f[x]=y;
	for (int i=next[x];i;i=edge[i].next){
			flag|=dfs(edge[i].to,y,z|1);
	}
	return flag;
}
char s[1010];
int hash(char *s) {
	return (s[0]-'a')*26+(s[1]-'a')+1;
}
int b[maxn][maxn];
bool fail(){
	for (int i=1;i<=maxk;i++) {
		if (dfs(i,i,0)) return 0;
	}
	return 1;
}
int main(){
	int n;
	scanf("%d\n",&n);
	int mlen=0;
	for (int i=1;i<=n;i++) {
		scanf("%s",s);
		int len=strlen(s);
		b[hash(s)][hash(s+len-2)]=max(len,b[hash(s)][hash(s+len-2)]);
		mlen=max(mlen,len);
	}
	for (int i=1;i<maxk;i++)
	for (int j=1;j<maxk;j++) 
	if (b[i][j]>0) 
		addedge(i,j,b[i][j]);
	if (fail()) {printf("No solution.");return 0;}
	double l=1,r=mlen;
	while (r-l>0.005) {
		double mid=(l+r)/2;
	//	printf("%lf\n",mid);
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%lf\n",(l+r)/2);
	return 0;
}
