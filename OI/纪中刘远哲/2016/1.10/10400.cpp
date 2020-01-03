#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 30, MAXM = 30, MAXS = 20000;
int n, m;
int a[MAXN][2], f[MAXM][MAXS * 2], v[MAXM][MAXM], s[MAXM];

void Work(){
	memset(a, 0 ,sizeof(a));
	memset(f, 0, sizeof(f));
	memset(v, 0, sizeof(v));
	memset(s, 0, sizeof(s));
	
	for(int i = 1; i <= n; i ++)
		scanf("%d %d", &a[i][0], &a[i][1]);
	
	scanf("%d", &m);
	for(int i = 1; i <= m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		for(int j = 1; j <= x; j ++){
			int xx;
			scanf("%d", &xx);
			for(int k = 1; k <= m; k ++) 
				if(v[i][k] >= 0 && a[xx][0] - a[xx][1] * (k - 1) >= 0) v[i][k] += a[xx][0] - a[xx][1] * (k - 1);
				else v[i][k] = -1;
			s[i] += 1 << (xx - 1);
		}
		for(int k = 1; k <= m; k ++)
			if(v[i][k] >= 0) v[i][k] += y;
	}
	
	for(int i = 1; i <= m; i ++)
		for(int S = 0; S <= MAXS; S ++){
			f[i][S] = f[i - 1][S];
			for(int j = 1; j <= m; j ++){
				if((S & s[j]) != s[j]) continue;
				int SS = S - s[j];
				f[i][S] = max(f[i][S], f[i - 1][SS] + v[j][i]);
			}
		}
	
	int ans = 0;
	for(int S = 0; S <= MAXS; S ++) ans = max(ans, f[m][S]);
	printf("%d\n", ans);
}

int main(){
	freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	
	while(scanf("%d", &n) && n != 0) Work();
	
	return 0;
}

