#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 4100;
int map[N][N];
int T;

void print(int n) {
    for (int i = 1; i <= (1 << n); i++) {
        for (int j = 1; j <= (1 << n); j++) {
            if (map[i][j]) printf("P"); else printf("C");
        }
        puts("");
    }
}

void dfs(int n) {
    for (int x = 1; x <= (1 << n); x++) {
        for (int y = 1; y <= (1 << n); y++) {
            int t = (1<<(n-1));
            int i = x/t+(x%t!=0),j = y/t+(y%t!=0);
            map[x][y] = map[(x%t)==0?t:x%t][(y%t)==0?t:y%t];
            if (i==2 && j==1) map[x][y] = !map[x][y];
        }
    }
}

int main() {
    cin >> T;
    for (int n=1;n<=10;n ++) dfs(n);
    while (T--) {
        int n;
        cin >> n;
        print(n);
    }
    return 0;
}