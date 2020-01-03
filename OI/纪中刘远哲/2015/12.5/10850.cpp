#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MAXN = 5, MAXS = 44000000, INF = 2147483647;
const int opp1[3] = {1, 2, 0}, opp2[3] = {2, 0, 1};
int n, m, Ans, ans, R;
int a[MAXN][MAXN], n3[MAXN][MAXN], aa[MAXN][MAXN];
int f[2][MAXS / 4], H[MAXS / 4];
struct Queue{
	int step, kind, t;
} Q[MAXS / 4];

int Hash(int t){
	int mo = MAXS / 4 - 10, x = t;
	t = t % mo + 1;
	while(H[t] != 0 && H[t] != x) t = t % mo + 1;
	H[t] = x;
	return t;
}

int Change(){
	int ret = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			ret = ret + a[i][j] * n3[i][j];
	return ret;
}

void Dfs(int step);

void Change1(int x, int y, int step, int kind){
	int t = a[x][y], tt;
	a[x][y] = a[x - 1][y];
	a[x - 1][y] = a[x - 1][y - 1];
	a[x - 1][y - 1] = a[x][y - 1];
	a[x][y - 1] = t;
	t = Change(), tt = Hash(t);
	if(!f[kind][tt]){
		f[kind][tt] = step + 1;
		if(f[kind ^ 1][tt]){ans = step + 1 + f[kind ^ 1][tt]; return;}
		R = R % (MAXS / 5) + 1;
		Q[R].t = t;
		Q[R].step = step + 1;
		Q[R].kind = kind;
	}
	t = a[x][y];
	a[x][y] = a[x][y - 1];
	a[x][y - 1] = a[x - 1][y - 1];
	a[x - 1][y - 1] = a[x - 1][y];
	a[x - 1][y] = t;
}

void Change2(int x, int y, int step, int kind){
	a[x - 1][y - 1] = opp1[a[x - 1][y - 1]];
	a[x - 1][y] = opp1[a[x - 1][y]];
	a[x][y - 1] = opp1[a[x][y - 1]];
	a[x][y] = opp1[a[x][y]];
	int t = Change(), tt = Hash(t);
	if(!f[kind][tt]){
		f[kind][tt] = step + 1;
		if(f[kind ^ 1][tt]){ans = step + 1 + f[kind ^ 1][tt]; return;}
		R = R % (MAXS / 5) + 1;
		Q[R].t = t;
		Q[R].step = step + 1;
		Q[R].kind = kind;
	}
	a[x - 1][y - 1] = opp2[a[x - 1][y - 1]];
	a[x - 1][y] = opp2[a[x - 1][y]];
	a[x][y - 1] = opp2[a[x][y - 1]];
	a[x][y] = opp2[a[x][y]];
}

void Change3(int x, int y, int step, int kind){
	int t = a[x][y], tt;
	a[x][y] = a[x][y - 1];
	a[x][y - 1] = a[x - 1][y - 1];
	a[x - 1][y - 1] = a[x - 1][y];
	a[x - 1][y] = t;
	t = Change(), tt = Hash(t);
	if(!f[kind][tt]){
		f[kind][tt] = step + 1;
		if(f[kind ^ 1][tt]){ans = step + 1 + f[kind ^ 1][tt]; return;}
		R = R % (MAXS / 5) + 1;
		Q[R].t = t;
		Q[R].step = step + 1;
		Q[R].kind = kind;
	}
	t = a[x][y];
	a[x][y] = a[x - 1][y];
	a[x - 1][y] = a[x - 1][y - 1];
	a[x - 1][y - 1] = a[x][y - 1];
	a[x][y - 1] = t;
}

void Change4(int x, int y, int step, int kind){
	a[x - 1][y - 1] = opp2[a[x - 1][y - 1]];
	a[x - 1][y] = opp2[a[x - 1][y]];
	a[x][y - 1] = opp2[a[x][y - 1]];
	a[x][y] = opp2[a[x][y]];
	int t = Change(), tt = Hash(t);
	if(!f[kind][tt]){
		f[kind][tt] = step + 1;
		if(f[kind ^ 1][tt]){ans = step + 1 + f[kind ^ 1][tt]; return;}
		R = R % (MAXS / 5) + 1;
		Q[R].t = t;
		Q[R].step = step + 1;
		Q[R].kind = kind;
	}
	a[x - 1][y - 1] = opp1[a[x - 1][y - 1]];
	a[x - 1][y] = opp1[a[x - 1][y]];
	a[x][y - 1] = opp1[a[x][y - 1]];
	a[x][y] = opp1[a[x][y]];
}

void ChangeB(int t){
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++){
			a[i][j] = t % 3;
			t /= 3;
		}
}

void Bfs(int step){
	memset(Q, 0, sizeof(Q));
	int t = Change();
	Q[1].t = t;
	Q[1].step = 0;
	Q[1].kind = 0;
	Q[2].t = Ans;
	Q[2].step = 0;
	Q[2].kind = 1;
	R = 2;
	for(int L = 1; L != R + 1; L = L % (MAXS / 5) + 1){
		ChangeB(Q[L].t);
		step = Q[L].step;
		if(ans != INF) return;
		for(int i = 2; i <= n; i ++)
			for(int j = 2; j <= m; j ++){
				if(!Q[L].kind && ans == INF){
					Change1(i, j, step, Q[L].kind);
					if(ans != INF) return;
					Change2(i, j, step, Q[L].kind);
				}
				else if(ans == INF){
					Change3(i, j, step, Q[L].kind);
					if(ans != INF) return;
					Change4(i, j, step, Q[L].kind);
				}
			}
	}
}

bool Work(){
	memset(H, 0, sizeof(H));
	memset(f, 0, sizeof(f));
	scanf("%d", &n);
	if(!n) return 0;
	scanf("%d", &m);
	n3[1][1] = 1;
	for(int i = 1; i <= n; i ++){
		if(i > 1) n3[i][1] = n3[i - 1][m] * 3;
		for(int j = 2; j <= m; j ++) n3[i][j] = n3[i][j - 1] * 3;
	}
	for(int i = 1; i <= n; i ++){
		char c = getchar();
		for(int j = 1; j <= m; j ++){
			c = getchar();
			if(c == 'R') a[i][j] = 0;
			else if(c == 'B') a[i][j] = 1;
			else a[i][j] = 2;
		}
	}
	Ans = 0;
	for(int i = 1; i <= n; i ++){
		char c = getchar();
		for(int j = 1; j <= m; j ++){
			c = getchar();
			int t;
			if(c == 'R') aa[i][j] = 0;
			else if(c == 'B') aa[i][j] = 1;
			else aa[i][j] = 2;
			Ans += aa[i][j] * n3[i][j];
		}
	}
	ans = INF;
	Bfs(0);
	if(ans == INF) printf("-1\n");
	else printf("%d\n", ans);
	return 1;
}

int main(){
	freopen("b.in", "r", stdin), freopen("b.out", "w", stdout);
	
	while(Work());
	
	return 0;
}

