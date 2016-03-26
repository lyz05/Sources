#include<cstdio>

const int N=1100000,M=22;
int n,m,i,j,v,u,tot,type,ans;
int fa[N],rf[N],point[N*2],next[N*2],g[N],p[N],a[N][3],b[N],aa[N],dep[N];

void add(int x,int y) {
	point[++tot]=y;
	next[tot]=g[x];
	g[x]=tot;
}

void bfs() {
	aa[1]=1;
	int l=0,r=1;
	b[1]=true;
	while (l<=r) {
		int u=aa[++l];
		for (int i=g[u];i;i=next[i]) {
			int j=point[i];
			if (!b[j]) {
				aa[++r]=j;
				b[j]=true;
				dep[j]=dep[u]+1;
				fa[j]=u;
				rf[j]=i/2+i%2;
			}
		}
	}
}

void work(int u,int v){
	if (dep[u]<dep[v]) {
		int tmp=u;u=v;v=tmp;
	}
	while (dep[u]>dep[v]) {
		p[rf[u]]=true;
		u=fa[u];
	}
	while (u!=v) {
		p[rf[u]]=true;
		p[rf[v]]=true;
		u=fa[u];
		v=fa[v];
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (i=1;i<n;i++) {
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dep[1]=1;
	bfs();
	for (i=1;i<=m;i++) {
		scanf("%d",&type);
		if (type==1) {
			scanf("%d",&v);
			ans=0;
			for (;v;v=fa[v]) {
				if (p[rf[v]]) {
					ans=rf[v];
					break;
				}
			}
			printf("%d\n",ans);
		}
		else {
			scanf("%d%d",&u,&v);
			work(u,v);
		}
	}
	return 0;
}
