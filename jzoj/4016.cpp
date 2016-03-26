#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int N=55;
const int flag[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char s[N][N];
int n,m,i,j,tt,ns;
int f[N*N*(1<<10)][4],ans[11],num[11][3];
bool p[N][N][1<<10];

void bfs(int x,int y) {
	int l=0,r=1;
	f[1][1]=x;
	f[1][2]=y;
	f[1][0]=0;
	while (l<r) {
		x=f[++l][1];
		y=f[l][2];
		int state=f[l][0],now=0;
		if (x==0&&y==0&&l!=1) {
			bool ok=true;
			int nt=0,sum=0;
			while (state) {
				now=state%2;
				state/=2;
				nt++;
				if (now) {
					if (s[num[nt][1]][num[nt][2]]=='X') {
						ok=false;
						break;
					}
					else sum++;
				}
			}
			if (ok&&!ans[sum]) ans[sum]=f[l][3];
			continue;
		}
		for (int i=0;i<=3;i++) {
			int x1=x+flag[i][0];
			int y1=y+flag[i][1];
			if (x1>n||y1>m||x1<0||y1<0) continue;
			now=state;
			if (i<=1) { 
				for (int j=1;j<=tt;j++) 
					if (num[j][2]==max(y,y1)&&num[j][1]>x1)
					       	now^=(1 << (j-1));
			}
			if (p[x1][y1][now]) continue;
			p[x1][y1][now]=true;
			f[++r][1]=x1;
			f[r][2]=y1;
			f[r][0]=now;
			f[r][3]=f[l][3]+1;
		}
	}
}

int main() {
	freopen("4016.in","r",stdin);

	while (gets(s[++n])) {
		if (n==1) m=strlen(s[1]);
		for (i=m;i;i--) {
			s[n][i]=s[n][i-1];
			if (s[n][i]!='.') {
				num[++tt][1]=n;
				num[tt][2]=i;
				if (s[n][i]=='I') ns++;
			}
		}
	}
	n--;
	bfs(0,0);
	for (i=1;i<=ns;i++) printf("%d\n",ans[i]);
	return 0;
}
