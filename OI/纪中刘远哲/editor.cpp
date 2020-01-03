#include <cstdio>
#include <algorithm>

const int N = 1000000 + 10, INF = 1e9 + 10;

int tcase, cursor;
int mx[N], val[N], tot;
int left[N], right[N], x[N], n;

int main() {

	cursor = 0;
	val[0] = 0, mx[0] = -INF;
	for (int i = 0; i < N; ++i) left[i] = right[i] = i;
	for (scanf("%d", &tcase); tcase--;) {
		char op;
		int k;
		scanf(" %c", &op);
		switch (op) {
			case 'I':
				++n;
				scanf("%d", x + n);
				right[n] = right[cursor];
				left[right[cursor]] = n;
				left[n] = cursor;
				right[cursor] = n;
				++tot;
				val[tot] = val[tot - 1] + x[n];
				mx[tot] = std::max(mx[tot - 1], val[tot]);
				cursor = n;
				break;
			case 'D':
				right[left[cursor]] = right[cursor];
				left[right[cursor]] = left[cursor];
				--tot;
				cursor = left[cursor];
				break;
			case 'L':
				cursor = left[cursor];
				--tot;
				break;
			case 'R':
				cursor = right[cursor];
				++tot;
				val[tot] = val[tot - 1] + x[cursor];
				mx[tot] = std::max(mx[tot - 1], val[tot]);
				break;
			case 'Q':
				scanf("%d", &k);
				printf("%d\n", mx[k]);
		}
	}
	return 0;
}
