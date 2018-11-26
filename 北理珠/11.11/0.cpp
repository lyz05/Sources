#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 16;
int g[N][N], t[N][N], f[N][N];
int cnt, n, m;
int x[4] = {0, 0, -1, 1};
int y[4] = { -1, 1, 0, 0};
 
void flip(int i, int j)//翻转
{
    ++cnt, f[i][j] = 1;//步数加1，记录翻转了哪个瓷砖
    t[i][j] = !t[i][j];//首先翻转自己
    for(int k = 0; k < 4; ++k)//向四个方向寻找，找到就翻转，这里使用了异或
        if(i + x[k] > -1 && j + y[k] > -1)
            t[i + x[k]][j + y[k]] ^= 1;
}
 
bool ok(int k)//对于第一行的每一种情况，判断是否能够产生最终的结果
{
    cnt = 0;//初始化步数
    memcpy(t, g, sizeof(t));//初始化临时数组，作为原始数组的副本
    for(int j = 0; j < m; ++j)//这里采用了二进制压缩，例如，j从0到3，那么1 << (m - 1 - j)的二进制就是1000,0100,0010,0001
        if(k & (1 << (m - 1 - j)))//对于k的每一个取值，如1010，找到不为0的列，因为只需要翻转1就可以了，用到了与运算
            flip(0, j);//如果某一列不为0，就翻转第一行的这个位置
 
 
    for(int i = 1; i < n; ++i)//当第一行全部翻转完了，原来为1的位置肯定是0，原来是0的位置肯定是1，这就需要第二行来解决这些为1位置，以此类推
        for(int j = 0; j < m; ++j)
            if(t[i - 1][j]) flip(i, j);//如果该列上一个位置是1，那么这个位置需要翻，否则不需要翻
 
    for(int j = 0; j < m; ++j)//因为每一行的1都可以由下一行搞定，但是最后一行没有下一行，所以只需要考察最后一行最后是不是全0就可以了
        if(t[n - 1][j]) return false;
    return true;
}
 
int main()
{
    int ans, p;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < n; ++i)//数据输入
            for(int j = 0; j < m; ++j)
                scanf("%d", &g[i][j]);
        ans = n * m + 1, p = -1;//初始化
        for(int i = 0; i < (1 << m); ++i)//i表示一个二进制数，用来枚举第一行的各种不同翻法，如0001就是只翻最后一个
            if(ok(i) && cnt < ans) //如果找到一种可能并且所用的步数更少的话，记下这种翻法
                ans = cnt, p = i;
 
        memset(f, 0, sizeof(f));
        if(p >= 0)//最后找到的就是最少的翻法，模拟一遍，然后输出
        {
            ok(p);
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                    printf("%d%c", f[i][j], j < m - 1 ? ' ' : '\n');
        }
        else puts("IMPOSSIBLE");
    }
    return 0;
}

