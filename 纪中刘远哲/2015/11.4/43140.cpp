#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int n, ans, maxa;
int ansa[MAXN], aa[MAXN], a[MAXN];

bool Judge(int x, int sum, int num, int lim){
	if(x == sum) return 1;
	if(sum > x) return 0;
	if(num > lim) return 0;
	bool t1 = Judge(x, sum + aa[num], num + 1, lim);
	if(t1) return 1;
	bool t2 = Judge(x, sum, num + 1, lim);
	return t2;
}

void Dfs(int x, int lim, int last){
	if(ans > 0) return;
	if(x > lim){
		for(int i = 1; i <= n; i ++)
			if(a[i] != a[i - 1] && !Judge(a[i], 0, 1, lim)) return;
		ans = lim;
		for(int i = 1; i <= lim; i ++) ansa[i] = aa[i];
		return;
	}
	for(int i = last; i <= maxa; i ++){
		aa[x] = i;
		Dfs(x + 1, lim, i);
		aa[x] = 0;
	}
}

void Work(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
		maxa = max(maxa, a[i]);
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i ++){
		Dfs(1, i, 1);
	}
	printf("%d\n", ans);
	for(int i = 1; i <= ans; i ++) printf("%d ", ansa[i]);
}

int main(){
	freopen("driver.in", "r", stdin), freopen("driver.out", "w", stdout);
	
	Work();
	
	return 0;
}
