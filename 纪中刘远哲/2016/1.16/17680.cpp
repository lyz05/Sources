/*
 * ID: j.sure.1
 * PROG:
 * LANG: C++
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define PB push_back
#define LL long long
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
/****************************************/
const int N = 105, M = 15, S = 65;
char s[M];
int mat[N], state[S], bomb[S];
int n, m, tot;
int dp[N][S][S];
//状态压缩DP

void init()
{
    tot = 0;
    memset(mat, 0, sizeof(mat));
    memset(state, 0, sizeof(state));
    memset(bomb, 0, sizeof(bomb));
    memset(dp, 0, sizeof(dp));
}

void input()
{
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        for(int j = 0; j < m; j++) {
            if(s[m-j-1] == 'H') mat[i] |= 1 << j;
        }
    }
}

void count(int k)
{
    while(k) {
        bomb[tot] += k & 1;
        k >>= 1;
    }
}

void pre_treat()
{
    //不允许互相攻击，存入state[]
    int lim = 1 << m;
    for(int i = 0; i < lim; i++) {
        if(i&(i>>1) || i&(i>>2)) continue;//左移右移都可以
        count(i);
        state[tot++] = i;
    }
}

void solve()
{
    //不允许放在山上
    for(int i = 0; i < tot; i++) {
        if(state[i] & mat[0]) continue ;
        dp[0][i][0] = bomb[i];//设-1行的状态为0
    }
    for(int i = 0; i < tot; i++) {//枚举第二行
        if(state[i] & mat[1]) continue ;
        for(int j = 0; j < tot; j++) {//枚举第一行
            if(state[j] & mat[0]) continue ;
            if(state[i] & state[j]) continue ;
            dp[1][i][j] = max(dp[0][j][0] + bomb[i], dp[1][i][j]);
        }
    }
    for(int r = 2; r < n; r++) {
        for(int i = 0; i < tot; i++) {
            if(state[i] & mat[r]) continue ;
            for(int j = 0; j < tot; j++) {
                if(state[j] & mat[r-1]) continue ;
                if(state[i] & state[j]) continue ;
                for(int k = 0; k < tot; k++) {
                    if(state[k] & mat[r-2]) continue ;
                    if(state[j] & state[k]) continue ;
                    if(state[i] & state[k]) continue ;
                    dp[r][i][j] = max(dp[r][i][j], dp[r-1][j][k] + bomb[i]);
                }
            }
        }
    }
}

int main()
{
    //freopen("1768.in", "r", stdin);
    //freopen("999.out", "w", stdout);

    scanf("%d%d", &n, &m);
    init();
    input();
    pre_treat();
    solve();
    int ans = 0;
    for(int i = 0; i < tot; i++) {
        for(int j = 0; j < tot; j++) {
            ans = max(ans, dp[n-1][i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
