#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

class Point
{
public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point() {}
    int x, y;
} K, G;

const int M = 15;
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int dirma[8][2][2] = {{{1, 2}, {1, 1}}, {{2, 1}, {1, 1}},{{-1, 2}, {-1, 1}}, {{-2, 1}, {-1, 1}},{{1, -2}, {1, -1}}, {{2, -1}, {1, -1}},{{-1, -2}, {-1, -1}}, {{-2, -1}, {-1, -1}}};
int T, n;
char map[M][M];

//判断棋子位置是否合法（边界判断）
bool legal(Point p)
{
    return (p.x >= 1 && p.y >= 1 && p.x <= 10 && p.y <= 9);
}
//判断是否遇到障碍物（棋子或边界）
bool judge(Point p)
{
    if (!legal(p))
        return 1;
    return map[p.x][p.y] != '.';
}

//判断p点位置是否为ch
bool judge(Point p, char ch)
{
    if (!legal(p))
        return 0;
    return map[p.x][p.y] == ch;
}

bool find(Point K, int flag)
{
    //兵
    bool ret = 0;
    if (K.x <= 5)
        ret |= judge(Point(K.x + 1, K.y), flag ? 'P' : 'p');
    if (K.x > 5)
        ret |= judge(Point(K.x - 1, K.y), flag ? 'P' : 'p');
    ret |= judge(Point(K.x, K.y + 1), flag ? 'P' : 'p');
    ret |= judge(Point(K.x, K.y - 1), flag ? 'P' : 'p');

    //车炮
    for (int j = 0; j < 4; j++)
    {
        int cnt = 0; 
        for (int i = 1;legal(Point(K.x + i * dir[j][0], K.y + i * dir[j][1])); i++)
        {
            Point now = Point(K.x + i * dir[j][0], K.y + i * dir[j][1]);
            cnt += judge(now);//计算遇到棋子的次数
            if (cnt == 1 && judge(now, flag ? 'R' : 'r')) //车
                ret |= 1;
            if (cnt == 2 && judge(now, flag ? 'C' : 'c')) //炮
                ret |= 1;
        }
    }
    //马
    for (int j = 0; j < 8; j++)
    {
        //马脚
        if (!judge(Point(K.x + dirma[j][1][0], K.y + dirma[j][1][1])))
        {
            ret |= judge(Point(K.x + dirma[j][0][0], K.y + dirma[j][0][1]), flag ? 'N' : 'n');
        }
    }
    return ret;
}

int main()
{
    freopen("C.in", "r", stdin);
    //freopen(".out","w",stdout);

    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 9; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'K')
                    K.x = i, K.y = j;
                if (map[i][j] == 'G')
                    G.x = i, G.y = j;
            }
        cout << "Case #" << t << ":" << endl;
        if (find(K, 1) || find(G, 0))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
