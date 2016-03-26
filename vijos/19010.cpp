#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

struct Change{
    int x , y , z , s1 , s2;
};

const int N = 100010;
Change a1[4 * N] , a2[4 * N];
LL f[8 * N] , ans;
int t;

bool Dox(Change A , Change B){return A.x < B.x;}

LL Min(LL x , LL y){
    if (x == -1) return y;
    if (y == -1) return x;
    return min(x , y);
}

LL Ask(int s , int l , int r , int x , int y){
    if (l == x && r == y) return f[s];
    int mid = (l + r) / 2;
    if (y <= mid) return Ask(s * 2 , l , mid , x , y);
    else if (x > mid) return Ask(s * 2 + 1 , mid + 1 , r , x , y);
    else return Min(Ask(s * 2 , l , mid , x , mid) , Ask(s * 2 + 1 , mid + 1 , r , mid + 1 , y));
}

void Putin(int s , int l , int r , int x , LL z){
    if (l == x && r == x){
        f[s] = Min(z , f[s]);
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid) Putin(s * 2 , l , mid , x , z);
    else Putin(s * 2 + 1 , mid + 1 , r , x , z);
    f[s] = Min(f[s * 2] , f[s * 2 + 1]);
}

void Work(){
    int n , m;
    scanf("%d %d" , &n , &m);
    memset(a1 , 0 , sizeof(a1));
    memset(a2 , 0 , sizeof(a2));
    int t = 0;
    for(int i = 1; i <= n; i ++)
        scanf("%d %d %d" , &a1[i].x , &a1[i].y , &a1[i].z);
    if (m == 1){
        ans = 0;
        return;
    }
    sort(a1 + 1 , a1 + 1 + n , Dox);
    for(int i = 1; i <= n; i ++){
        a2[i].x = a1[i].x; a2[i + n].x = a1[i].y;
        a2[i].s1 = i; a2[i].s2 = 1;
        a2[i + n].s1 = i; a2[i + n].s2 = 2;
    }
    sort(a2 + 1 , a2 + 1 + 2 * n , Dox);
    t = 1; int last = 1; bool bb = 1;
    for(int i = 1; i <= 2 * n; i ++){
        if (a2[i].x != last){
            t ++;
            if (bb && a2[i].x >= m){
                bb = 0;
                m = t;
                if (a2[i].x > m) t ++;
            }
            last = a2[i].x;
        }
        if (a2[i].s2 == 1) a1[a2[i].s1].x = t;
        else a1[a2[i].s1].y = t;
    }
    memset(f , 255 , sizeof(f));
    Putin(1 , 1 , t , 1 , 0);
    a1[0].x = 1; ans = -1;
    bb = 1;
    for(int i = 1; i <= n; i ++) if (a1[i].y == 1){
        bb = 0;
    }
    for(int i = 1; i <= n; i ++){
        LL tt = -1;
        if (a1[i - 1].x >= a1[i].y) tt = Ask(1 , 1 , t , a1[i].y , a1[i - 1].x);
        if (tt != -1){
            tt += a1[i].z;
            Putin(1 , 1 , t , a1[i].x , tt);
            if (a1[i].x >= m) ans = Min(ans , tt);
        }
    }
    ans = ans;
}

int main(){
    freopen("a.in" , "r" , stdin);
    freopen("a.out" , "w" , stdout);

    scanf("%d" , &t);
    for(int i = 1; i <= t; i ++){
        Work();
        printf("Case #%d: %lld\n" , i , ans);
    }

    return 0;
}
