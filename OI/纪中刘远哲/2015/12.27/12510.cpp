#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
FILE * *out;
typedef long long int ll;
ll q[3000001];
ll f[10001];
ll a[10001];
ll d[10001];
ll v[10001];
ll b[10001][251];
ll c[10001][251];
ll n, m, st, ed, tt, limit, tot;
void find_it(ll s, ll t)
{
    ll i, j, x, tmp;
    i = s;
    j = t;
    x = f[(i + j) / 2];
    while (i <= j) {
        while (f[i] < x) { ++i; }
        while (f[j] > x) { --j; }
        if (i <= j) {
                tmp = f[i];
                f[i] = f[j];
                f[j] = tmp;
                ++i;
                --j;
        }
    }
    if (s < j) find_it(s, j);
    if (i < t) find_it(i, t);        
}
void spfa(ll s)
{
    ll i, head, tail, now;
    sizeof(v, 0, sizeof(v));
    for (i = 1; i <= n; ++i) d[i] = 0x7fffffff;
    d[s] = 0;
    q[1] = s;
    head = 1;
    tail = 1;
    v[s] = 1;
    while (head <= tail) {
        now = q[head];
        for (i = 1; i <= b[now][0]; ++i) {
                if (a[b[now][i]]<=limit) {
                    if (d[b[now][i]]>d[now]+c[now][i]) {
                            d[b[now][i]] = d[now]+c[now][i];
                            if (v[b[now][i]] == 0) {
                                v[b[now][i]] = 1;
                                ++tail;
                                q[tail] = b[now][i];
                            }
                    }
                }
        }
        ++head;
        v[now] = 0;
    }
}
void process(ll s, ll t)
{
    ll mid;
    if (s == t) { printf( "%d\n", f[s]);return ;}
    mid = (s + t) / 2;
    limit = f[mid];
    spfa(st);
    if (d[ed] > tt) process(mid + 1, t);
    else process(s, mid);
}
int main()
{
    //in = fopen("cost.in", "rt");
    //out = fopen("cost.out", "wt");
    ll s, t, l, i, lim;
    scanf( "%lld%lld%lld%lld%lld", &n, &m, &st, &ed, &tt);
    for (i = 1; i <= n; ++i) scanf( "%lld", &a[i]);
    if (a[st] > a[ed]) lim = a[st];
    else lim = a[ed];
    for (i = 1; i <= n; ++i) {
        if (a[i] >= lim) {
                ++tot;
                f[tot] = a[i];
        }
    }
    find_it(1, tot);
    for (i = 1; i <= m; ++i) {
        scanf( "%lld%lld%lld", &s, &t, &l);
        ++b[s][0];
        b[s][b[s][0]] = t;
        c[s][b[s][0]] = l;
        ++b[t][0];
        b[t][b[t][0]] = s;
        c[t][b[t][0]] = l;
    }
    limit = 1000000001;
    spfa(st);    
    if (d[ed] > tt)  { printf( "-1\n");return 0;}
    process(1, tot);
    return 0;
}
