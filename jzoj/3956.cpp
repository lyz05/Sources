#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
//#define ONLINE_JUDGE

using namespace std;

const int N=305;

struct circle{
	double x,y,r;
} plane[N];

long mark[N][2],map[N][N];
long n,index1;
bool can;


double sqr(double x) {
	return(x*x);
}
/*
double distance(circle a,circle b){
	double x=sqr(a.x-b.x),y=sqr(a.y-b.y);
	return(sqrt(x+y));
}
*/

long calc(circle a,circle b){
	circle c=plane[n+1];
	double x=(c.y-a.y)/(b.y-a.y)*(b.x-a.x)+a.x;
	if (a.y==b.y) return 0;
	if (c.y>=max(a.y,b.y)) return 0;
	if (c.y<min(a.y,b.y)) return 0;
	if (c.x<x) return 1; else return 0;
}

void walk(long x,long s){
	mark[x][s]=index1;
	for(long y=1;y<=n;y++) 
		if ((map[x][y]>=0) && (mark[y][s^map[x][y]]<index1)) 
			walk(y,s^map[x][y]);

}

void clear(){
	memset(map,255,sizeof(map));
	memset(mark,0,sizeof(mark));
	can=true;
}

void scan(){
	//scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>plane[i].x>>plane[i].y>>plane[i].r;
	cin>>plane[n+1].x>>plane[n+1].y>>plane[n+1].r;
	for(int i=1;i<=n;i++) plane[i].r+=plane[n+1].r;
}

void solve(){
	long i,j;
	for(i=1;i<=n-1;i++){
		for(j=i+1;j<=n;j++){
			double t1=sqr(plane[i].x-plane[j].x)+
				sqr(plane[i].y-plane[j].y);
			double t2=sqr(plane[i].r+plane[j].r);
			if (t1<t2)
			{
				map[i][j]=calc(plane[i],plane[j]);
				map[j][i]=map[i][j];
			}
		}
	}
	index1=0;
	for(i=1;i<=n;i++){
		index1++;
		walk(i,0);
		for(j=1;j<=n;j++){
			if ((mark[j][0]==index1) && (mark[j][1]==index1)){
				can=false;
				break;
			}
		}
		if (!can) break;
	}
}

void print(){
	if (can) printf("YES\n"); else printf("NO\n");
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("3956.in", "r", stdin);
#endif
	while(scanf("%d",&n)!=EOF) {
		clear();
		scan();
		solve();
		solve();
		print();
	}
	return 0;
}
