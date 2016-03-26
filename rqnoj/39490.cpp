#include <bits/stdc++.h>

const int N = 800 + 10;

int n, m, k, lim;
char map[N][N];

std::bitset<N> state[N], ok[N];

int next[N][N], *cur;

#define FAIL { puts("-1"); return 0; }

inline bool cmp(int a, int b) { return cur[a] < cur[b]; }

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d%d%d", &n, &m, &k, &lim);
  for (int i = 0; i < n; ++i) scanf(" %s", map[i]);
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      ok[i][j] = (map[j][i] == '1');
  memset(next, -1, sizeof next);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (ok[i][j]) {
        if (i && ok[i - 1][j])
          next[i][j] = next[i - 1][j];
        else
          for (next[i][j] = i; ok[next[i][j]][j];) next[i][j]++;
      }
    }
  }
  state[0] = ok[0];
  for (int i = 1; i < m; ++i) {
    state[i] = state[i - 1] & ok[i];
    static std::vector<int> q;
    q.clear();
    cur = next[i];
    for (int j = 0; j < n; ++j)
      if (ok[i][j] && !state[i][j])
        q.push_back(j);
    std::make_heap(q.begin(), q.end(), cmp);
    for (int tmp = lim; tmp-- && !q.empty();) {
      state[i][q.front()] = 1;
      std::pop_heap(q.begin(), q.end(), cmp);
      q.pop_back();
    }
    if (state[i].count() < k) FAIL;
  }
  for (int i = m - 1; i >= 0; --i)
    for (int j = 0; j < n && state[i].count() > k; ++j)
      if (state[i][j] && !state[i + 1][j]) state[i][j] = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j)
      if (state[i][j]) printf("%d ", j + 1);
    putchar('\n');
  }
  return 0;
}
