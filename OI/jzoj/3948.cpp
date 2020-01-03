#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100;
typedef long long ll;
ll f[N], g[N];
int n, m;

ll Work(int s1, int t1, int s2, int t2, int n, int k) {
	if (n == 0) return 0;
	int k1 = 6 - s1 - t1;
	int k2 = 6 - s2 - t2;
	//d1
	if (k <= f[n - 1]) {
		int d1 = s1;
		// s2 -> k2 -> t2
		if (s2 == d1) return Work(s1, k1, s2, t2, n - 1, k);
		if (k2 == d1) return Work(s1, k1, t2, s2, n - 1, k) + g[n - 1] + 1;
		if (t2 == d1) return Work(s1, k1, s2, t2, n - 1, k) + 2 * g[n - 1] + 2;
	} else {
		int d1 = t1;
		// s2 -> k2 -> t2
		if (s2 == d1) return Work(k1, t1, s2, t2, n - 1, k - f[n - 1] - 1);
		if (k2 == d1) return Work(k1, t1, t2, s2, n - 1, k - f[n - 1] - 1) + g[n - 1] + 1;
		if (t2 == d1) return Work(k1, t1, s2, t2, n - 1, k - f[n - 1] - 1) + 2 * g[n - 1] + 2;
	}
}

int main() {
	
	for (int i = 1; i <= 20; i++) {
		f[i] = 1 + f[i - 1] * 2;
		g[i] = 2 + g[i - 1] * 3;
	}
	
	scanf("%d%d", &n, &m);
	printf("%lld\n", Work(1, 3, 1, 3, n, m));
	
	return 0;
}
