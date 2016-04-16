#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,s,e,k,nf,fb[52][52]={0},p[52];
struct mtx{
  int num[52][52];
  mtx(){	memset(num,0,sizeof(num));}
}M[12],org;
mtx mul(mtx a,mtx b){
  mtx c;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      for(int k=0;k<n;k++)
        c.num[i][j]=(c.num[i][j]+a.num[i][k]*b.num[k][j])%10000;
  return c;
}mtx pow(mtx a,int b){
  mtx c;
  for(int i=0;i<n;i++)	c.num[i][i]=1;
  while(b){
    if(b&1)	c=mul(c,a);
    b>>=1;
    a=mul(a,a);
  }return c;
}inline void clear1(int x,int y){
  for(int i=0;i<n;i++)	M[x].num[y][i]=0;
}inline void clear2(int x,int y){
  for(int i=0;i<n;i++)	M[x].num[i][y]=0;
}int main(){
	freopen("2288.in","r",stdin);
  scanf("%d%d%d%d%d",&n,&m,&s,&e,&k);
  int x,y,t;
  for(int i=0;i<m;i++){
    scanf("%d%d",&x,&y);
    for(int j=0;j<12;j++)	M[j].num[x][y]=M[j].num[y][x]=1;
  }scanf("%d",&nf);
  for(int i=0;i<nf;i++){
    scanf("%d",&t);
    for(int j=0;j<t;j++)	scanf("%d",&p[j]);
    for(int j=0;j<12;j++)	fb[j][p[j%t]]=1;
  }for(int j=0;j<12;j++)
    for(int i=0;i<n;i++)	if(fb[j][i])	clear1(j,i),clear2((j+11)%12,i);
  for(int i=1;i<12;i++)	M[i]=mul(M[i-1],M[i]);
  if(k%12)	cout << mul(pow(M[11],k/12),M[k%12-1]).num[s][e] << endl;
  else		cout << pow(M[11],k/12).num[s][e] << endl;
  return 0;
}
