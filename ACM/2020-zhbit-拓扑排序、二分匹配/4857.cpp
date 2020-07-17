#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 30000+10;
vector<int> E[N];
priority_queue<int> Q;
int T,m,n,in[N],ans[N];

int main(){
	freopen("F.in","r",stdin);
	//freopen("F.out","w",stdout);
	scanf("%d",&T);
	while (T --) { 
		ans[0] = 0;
		memset(in,0,sizeof in);
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i ++) E[i].clear();
		for (int i = 1;i <= m;i ++) {
			int x,y;
			scanf("%d%d",&x,&y);
			E[y].push_back(x);
			in[x] ++;
		}
		for (int i=1;i<=n;i ++)
			if (!in[i]) Q.push(i);
		while (!Q.empty()) {
			int now = Q.top();
			Q.pop();
			for (unsigned int i = 0;i < E[now].size();i ++) {
				int y = E[now][i];
				in[y] --;
				if (in[y] == 0) 
					Q.push(y);
			}
			ans[++ ans[0]] = now;
		}
		for (int i=ans[0];i>1;i --) printf("%d ",ans[i]);
		printf("%d\n",ans[1]);
	}
	return 0;
} 
