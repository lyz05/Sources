#include <cstdio>

const int MAXN = 1e5 + 10;
int n, ans, tots;
int Last[MAXN], a[MAXN];
struct side{
	int x, y;
} S[MAXN];

void Link(int x, int y){S[++ tots].x = y; S[tots].y = Last[x]; Last[x] = tots;}

void Dfs(int x, int last, int MAX){
	if(a[x] >= last) 
		if(MAX + 1 > ans) ans = MAX + 1;
	if(MAX > ans) ans = MAX;
	for(int p = Last[x]; p; p = S[p].y){
		int y = S[p].x;
		if(a[x] >= last) Dfs(y, a[x], MAX + 1);
		Dfs(y, last, MAX);
	}
}

void Work(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i ++){
		int x; scanf("%d", &x);
		Link(x, i);
	}
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	Dfs(1, 0, 0);
	printf("%d", ans);
}

int main(){
	//freopen("c.in", "r", stdin), freopen("c20.out", "w", stdout);
	
	Work();
	
	return 0;
}

