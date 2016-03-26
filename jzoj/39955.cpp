#include <cstdio>
#include <cstring>

const int N = 10 + 5;

int n;

char cube[N][N][N];

char view[6][N][N];

inline bool inside(int x, int y, int z) {
  return 0 <= x && x < n && 0 <= y && y < n && 0 <= z && z < n;
}

int paint(int dir) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int a, b, c, dx, dy, dz;
      dx = dy = dz = 0;
      switch (dir) {
        case 0:
          a = n - 1, b = j, c = i, dx = -1;
          break;
        case 1:
          a = j, b = 0, c = i, dy = 1;
          break;
        case 2:
          a = 0, b = n - 1 - j, c = i, dx = 1;
          break;
        case 3:
          a = n - 1 - j, b = n - 1, c = i, dy = -1;
          break;
        case 4:
          a = i, b = j, c = 0, dz = 1;
          break;
        case 5:
          a = n - 1 - i, b = j, c = n - 1, dz = -1;
          break;
      }
      while (inside(a, b, c) && cube[a][b][c] == '.') 
	      a += dx, b += dy, c += dz;
      while (inside(a, b, c) && view[dir][i][j] == '.') {
        cube[a][b][c] = '.';
        a += dx, b += dy, c += dz;
      }
      if (view[dir][i][j] == '.') continue;
      if (!inside(a, b, c) && view[dir][i][j] != '.') return -1;
      if (cube[a][b][c] && cube[a][b][c] != view[dir][i][j])
        cube[a][b][c] = '.', res = 1;
      else if (!cube[a][b][c])
        cube[a][b][c] = view[dir][i][j];
    }
  }
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("3995.in", "r", stdin);freopen("3995.out","w",stdout);
#endif
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < 6; ++j)
        scanf(" %s", view[j][i]);
    int ans = 0;
    memset(cube, 0, sizeof cube);
    while (1) {
      bool temp = false;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          for (int k = 0; k < n; ++k)
            if (cube[i][j][k] != '.') cube[i][j][k] = 0;
      for (int i = 0; i < 6; ++i) {
        int res = paint(i);
        if (res == -1) {
          ans = -1;
          break;
        } else {
          temp |= res;
        }
      }
      if (ans == -1 || !temp) break;
    }
    if (~ans) {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          for (int k = 0; k < n; ++k)
            ans += (cube[i][j][k] != '.');
    } else {
      ans = 0;
    }
    printf("Maximum weight: %d gram(s)\n", ans);
  }
  return 0;
  123.cpp
}
