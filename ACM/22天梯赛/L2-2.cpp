#include <bits/stdc++.h>
using namespace std;


const int N = 60*60*24*2,M = 60*60*24;
int a[N],n;

int main() {
    cin >> n;
    for (int i=0;i<n;i ++) {
        int h1,m1,s1,h2,m2,s2;
        scanf("%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int st = h1*3600+m1*60+s1,en = h2*3600+m2*60+s2;
        a[st] += 1;
        a[en] += -1;
        a[st+M] += 1;
        a[en+M] += -1;
    }
    int st = -1,en = -1;
    for (int i=1;i<N;i ++) {
        a[i] += a[i-1];
        if (a[i-1]>0 && a[i]==0)
            st = i;
        if (a[i-1]==0 && a[i]>0)
            en = i;
        if (st!=-1 && en!=-1){
            bool flag = false;
            if (st<M && en>M)
                flag = true;
            st = st%M;
            en = en%M;
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n",st/3600,st/60%60,st%60,en/3600,en/60%60,en%60);
            st = -1;
            en = -1;
            if (flag)
                break;
        }
    }
    return 0;
}
/*
2
00:00:02 - 00:00:03
00:00:04 - 00:00:05
*/