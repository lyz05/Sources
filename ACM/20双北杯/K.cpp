#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int T, a[4],ans[4];
char s[105],ss[5][105];

int main()
{
    freopen("K.in", "r", stdin);
    //freopen(".out","w",stdout);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ":" << endl;
        for (int i = 0; i < 3; i++)
        {
            int cnt = 0;
            memset(a,0,sizeof a);
            cin >> s;
            cnt = sscanf(s, "%dx+%dy+%dz+%d=%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
            cnt = sscanf(s, "%dx+%dy+%dz=%d",&a[0],&a[1],&a[2],&a[4]);
            cnt = sscanf(s, "%dx+%dz+%dy=%d",&a[0],&a[2],&a[1],&a[4]);
            cnt = sscanf(s, "%dy+%dx+%dz=%d",&a[1],&a[0],&a[2],&a[4]);
            cnt = sscanf(s, "%dy+%dz+%dx=%d",&a[1],&a[2],&a[0],&a[4]);
            cnt = sscanf(s, "%dx+%dz+%dy=%d",&a[0],&a[2],&a[1],&a[4]);
            
        }
    }
    return 0;
}
//ax+by+cz=d