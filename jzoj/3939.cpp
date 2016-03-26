#include <bits/stdc++.h>

const int N = 100000 + 10, LIM = 1000000 + 10;

int n, a[N];
std::vector<int> prime;

void preprocessing() {
  static bool flag[LIM];
  prime.clear();
  for (int i = 2; i < LIM; ++i) {
    if (!flag[i]) prime.push_back(i);
    for (int j = 0; j < prime.size() && i * prime[j] < LIM; ++j) {
      flag[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}

int min[LIM], sub[LIM], minid[LIM], subid[LIM];

std::vector<int> list, cnt;

#define sqr(x) ((x) * (x))

void factor(int x) {
  list.clear();
  cnt.clear();
  for (int i = 0; i < prime.size() && sqr(prime[i]) <= x; ++i) {
    if (x == 1) break;
    if (x % prime[i] == 0) {
      list.push_back(prime[i]);
      cnt.push_back(0);
      while (x % prime[i] == 0) {
        x /= prime[i];
        cnt.back()++;
      }
    }
  }
  if (x > 1) list.push_back(x), cnt.push_back(1);
}

inline void update(int num, int val, int curid) {
  if (val < min[num]) {
    sub[num] = min[num];
    subid[num] = minid[num]; 
    min[num] = val;
    minid[num] = curid;
  } else if (val < sub[num]) {
    sub[num] = val;
    subid[num]  = curid;
  }
}

void dfs(int dep, int num, int rem, int id) {
  if (dep == list.size()) {
    update(num, rem, id);
    return;
  }
  if (cnt[dep]) {
    cnt[dep]--;
    dfs(dep, num * list[dep], rem - 1, id);
    cnt[dep]++;
  }
  dfs(dep + 1, num, rem, id);
}

int best, id;

void solve(int dep, int num, int rem, int curid) {
  if (dep == list.size()) {
    int tmp = rem + (minid[num] == curid ? sub[num] : min[num]);
    int tid = (minid[num] == curid) ? subid[num] : minid[num];
    if (tmp < best || (tmp == best && tid < id)) {
      best = tmp;
      id = tid;
    }
    return;
  }
  if (cnt[dep]) {
    cnt[dep]--;
    solve(dep, num * list[dep], rem - 1, curid);
    cnt[dep]++;
  }
  solve(dep + 1, num, rem, curid);
}

int main() {
/*#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif*/
  scanf("%d", &n);
  preprocessing();
  memset(min, 0x3f, sizeof min);
  memset(sub, 0x3f, sizeof sub);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    factor(a[i]);
    dfs(0, 1, std::accumulate(cnt.begin(), cnt.end(), 0), i);
  }
  for (int i = 1; i <= n; ++i) {
    factor(a[i]);
    id = n + 1, best = INT_MAX;
    solve(0, 1, std::accumulate(cnt.begin(), cnt.end(), 0), i);
    printf("%d\n", id);
  }
  return 0;
}
