#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000000+7;
int n,m,q,t;
char s[N];

int main()
{
    freopen("G.in", "r", stdin);
    //freopen(".out","w",stdout);

    while (~scanf("%d%d%d",&n,&m,&q))
    {
        printf("Case #%d:\n",++ t);
        scanf("%s", s + 1);
        while (q--)
        {
            int op, pos;
            scanf("%d%d",&op,&pos);
            if (op == 1)
            {
                //pos,pos+m-1
                for (int i = pos, j = pos + m - 1; i < j; i++, j--)
                    swap(s[i], s[j]);
            }
            if (op == 2)
            {
                printf("%c",s[pos]);
            }
        }
        puts("");
    }

    return 0;
}
//1234
//1..4
//4321
//3..4
//4312
//2..3
//4132