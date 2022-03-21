#include <stdio.h>
#include <math.h>

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 计算完成整个抽检过程所需的最短时长
 * @param goods int整型一维数组 货物一维数组，元素是每件货物检查所需时长
 * @param goodsLen int goods数组长度
 * @return int整型
 * C语言声明定义全局变量请加上static，防止重复定义
 */

int min(int a, int b)
{
    return a < b ? a : b;
}

int minCheckDuration(int *goods, int goodsLen)
{
    // write code here
    const int N = 1e5 + 7;
    int f[N], i;
    for (i = 0; i < goodsLen; i++)
    {
        f[i] = goods[i];
        if (i > 1)
            f[i] = min(f[i] + f[i - 1], f[i] + f[i - 2]);
        else if (i > 0)
            f[i] = min(f[i] + f[i - 1], f[i]);
        printf("%d ", f[i]);
    }
    printf("\n");
    return min(f[goodsLen - 1], f[goodsLen - 2]);
}

int main()
{
    {
        int goods[] = {4, 9, 24};
        int goodsLen = 3;
        printf("%d\n", minCheckDuration(goods, goodsLen));
    }
    {
        int goods[] = {2, 100, 2, 3, 3, 90, 3, 2, 80, 2};
        int goodsLen = 10;
        printf("%d\n", minCheckDuration(goods, goodsLen));
    }
    return 0;
}