#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
const int N = 100000 + 9;
struct Link
{
    int nxt,pre;
}link[N];
int TOT,n,idx[N];
struct CITY
{
    int h,idx;
}city[N];
struct info
{
    int u;
    long long dis1,dis2;
    info(const int a = 0,const long long b = 0,const long long c = 0):u(a),dis1(b),dis2(c){}
}f[20][N][2];
//0: B
//1: A
inline bool cmp(const CITY &lhs,const CITY &rhs){return lhs.h < rhs.h;}
inline int getnext(const int i,const int t){return i?t:(t^1);}
void update(const int i,const int j,const int t)
{
    const int nxt = f[i - 1][j][t].u;
    const long long dis1 = f[i - 1][j][t].dis1,dis2 = f[i - 1][j][t].dis2;
    if (nxt) {
        info tmp;
        if ((tmp = f[i - 1][nxt][getnext(i - 1,t)]).u)
            f[i][j][t] = info(tmp.u,dis1 + tmp.dis1,dis2 + tmp.dis2);
    }
}
std::pair<int,int> go(int s,long long x)
{
    std::pair<int,int>tmp(0,0);
    int turn = 1; // A
    for (int i = TOT; i >= 0; --i) {
        if (!f[i][s][turn].u) continue;
        if (x - f[i][s][turn].dis1 - f[i][s][turn].dis2 < 0) continue;
        x -= f[i][s][turn].dis1 + f[i][s][turn].dis2;
        tmp.first  += f[i][s][turn].dis2;
        tmp.second += f[i][s][turn].dis1;
        turn = getnext(i,turn);
        s = f[i][s][turn].u;
    }
    return tmp;
}
inline void check(const int id_p,const int id_n,int &Min_h1,int &Min_i1,int &Min_h2,int &Min_i2)
{
    if (!id_n) return;
    const int dis = std::abs(city[id_p].h - city[id_n].h);
    if (dis < Min_h1 || dis == Min_h1 && city[id_n].h < city[Min_i1].h) {
        Min_h2 = Min_h1;
        Min_i2 = Min_i1;
        Min_h1 = dis;
        Min_i1 = id_n;
    }else if (dis < Min_h2 || dis == Min_h2 && city[id_n].h < city[Min_i2].h) {
        Min_h2 = dis;
        Min_i2 = id_n;
    }
}
inline long long cmp2(const std::pair<int,int>lhs,const std::pair<int,int>rhs)
{
    if (!lhs.second && !rhs.second) return 0;
    else if (!lhs.second) return 1;
    else if (!rhs.second) return -1;
    else return 1ll * lhs.first * rhs.second - 1ll * rhs.first * lhs.second;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    #endif
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&city[i].h);
        city[i].idx = i;
    }           
    std::sort(city + 1,city + 1 + n,cmp);
    for (int i = 1; i < n; ++i) {
        link[i].nxt = i + 1;
        link[i + 1].pre = i ;
        idx[city[i].idx] = i;
    }
    idx[city[n].idx] = n;
    for (int i = 1; i <= n; ++i) {
        int id = idx[i],Min_h1 = 0x7fffffff,Min_i1 = 0,Min_h2 = 0x7fffffff,Min_i2 = 0;
        check(id,link[id].pre,           Min_h1, Min_i1, Min_h2, Min_i2);
        check(id,link[id].nxt,           Min_h1, Min_i1, Min_h2, Min_i2);
        check(id,link[link[id].pre].pre, Min_h1, Min_i1, Min_h2, Min_i2);
        check(id,link[link[id].nxt].nxt, Min_h1, Min_i1, Min_h2, Min_i2);
        f[0][i][0] = info(city[Min_i1].idx,Min_h1,0);
        f[0][i][1] = info(city[Min_i2].idx,0,Min_h2);
        if (link[id].nxt) link[link[id].nxt].pre = link[id].pre;
        if (link[id].pre) link[link[id].pre].nxt = link[id].nxt;
    }
    TOT = static_cast<int>(ceil(log2((double)n)));
    for (int i = 1; i <= TOT; ++i)
        for (int j = 1; j <= n; ++j) {
            update(i,j,0);
            update(i,j,1);
        }
    int x;
    scanf("%d",&x);
    std::pair<int,int>ans;
    int ans_pos = 0;
    ans.first = 1; ans.second = 0;
    for (int i = 1; i <= n; ++i) {
        std::pair<int,int>tmp = go(i,x);
        if (cmp2(tmp,ans) < 0) {
            ans = tmp;
            ans_pos = i;
        }else if (cmp2(tmp,ans) == 0 && city[idx[ans_pos]].h < city[idx[i]].h) {
            ans = tmp;
            ans_pos = i;
        }
    }
    printf("%d\n",ans_pos);
    int m;
    scanf("%d",&m);
    for (int i = 1,x,s; i <= m; ++i) {
        scanf("%d%d",&s,&x);
        std::pair<int,int> tmp = go(s,x);
        printf("%d %d\n",tmp.first,tmp.second);
    }
}
