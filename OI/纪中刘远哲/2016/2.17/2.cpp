#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct node{
	int s,t,w;
}s[202];

int i,j,k,x,y,n,m,q/*[2]*/[202][2],f[202][202][202];
bool v[202][202];
char e;

bool cmp(node a , node b){
	return a.s<b.s;
}

int main(){
	scanf("%d%d%d%d%d\n",&n,&m,&x,&y,&k);
	memset(f,255,sizeof(f));
	memset(q,255,sizeof(q));
	f[0][x][y]=0;
	memset(v,0,sizeof(v));
	for(i=1;i<=n;i++){//the diff of n& m !caution!
		for(j=1;j<=m;j++){
			scanf("%c",&e);
			if(e=='x')v[i][j]=1;
		}
		scanf("\n");
	}
	for(i=1;i<=k;i++)scanf("%d%d%d",&s[i].s,&s[i].t,&s[i].w);
	int p=0;
	sort(s+1,s+k+1,cmp);
	//q[1][1][1]=x;q[1][1][0]=0;q[1][1][2]=y;
	for(i=1;i<=k;i++){
		if(s[i].w==1)
			for(y=m;y>=1;y--){
				int l=2,r=1;
				for(x=n;x>=1;x--){//sidejugdeCaution
					if(v[x][y]){
						l=2;r=1;
						q[l][1]=-1;
						continue;
					}
					while(abs(x-q[l][0])>s[i].t-s[i].s+1&&l<=r)l++;
					if(f[i-1][x][y]!=-1){
						while(f[i-1][x][y]-q[r][1]>abs(x-q[r][0])&&r>=l)r--;
						r++;
						q[r][1]=f[i-1][x][y];
						q[r][0]=x;
					}
					if(q[l][1]!=-1&&l<=r)f[i][x][y]=q[l][1]+abs(x-q[l][0]);
				}
			}	
		if(s[i].w==2)
			for(y=m;y>=1;y--){
				int l=2,r=1;
				for(x=1;x<=n;x++){//sidejugdeCaution
					if(v[x][y]){
						l=2;r=1;
						q[l][1]=-1;
						continue;
					}
					while(abs(x-q[l][0])>s[i].t-s[i].s+1&&l<=r)l++;
					if(f[i-1][x][y]!=-1){
						while(f[i-1][x][y]-q[r][1]>abs(x-q[r][0])&&r>=l)r--;
						r++;
						q[r][1]=f[i-1][x][y];
						q[r][0]=x;
					}
					if(q[l][1]!=-1&&l<=r)f[i][x][y]=q[l][1]+abs(x-q[l][0]);
				}
			}	

		if(s[i].w==3)
			for(x=n;x>=1;x--){
				int l=2,r=1;
				for(y=m;y>=1;y--){//sidejugdeCaution
					if(v[x][y]){
						l=2;r=1;
						q[l][1]=-1;
						continue;
					}
					while(abs(y-q[l][0])>s[i].t-s[i].s+1&&l<=r)l++;
					if(f[i-1][x][y]!=-1){
						while(f[i-1][x][y]-q[r][1]>abs(y-q[r][0])&&r>=l)r--;
						r++;
						q[r][1]=f[i-1][x][y];
						q[r][0]=y;
					}
					if(q[l][1]!=-1&&l<=r)f[i][x][y]=q[l][1]+abs(y-q[l][0]);
				}
			}	
		if(s[i].w==4)
			for(x=n;x>=1;x--){
				int l=2,r=1;
				for(y=1;y<=m;y++){//sidejugdeCaution
					if(v[x][y]){						
						l=2;r=1;
						q[l][1]=-1;
						continue;
					}
					while(abs(y-q[l][0])>s[i].t-s[i].s+1&&l<=r)l++;
					if(f[i-1][x][y]!=-1){
						while(f[i-1][x][y]-q[r][1]>abs(y-q[r][0])&&r>=l)r--;
						r++;
						q[r][1]=f[i-1][x][y];
						q[r][0]=y;
					}
					if(q[l][1]!=-1&&l<=r)f[i][x][y]=q[l][1]+abs(y-q[l][0]);
				}
			}
		memset(q,255,sizeof(q));
	}
	int ans;
	ans=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			ans=max(ans,f[k][i][j]);		
		}
	printf("%d",ans);
}
