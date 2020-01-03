
#include <stdio.h>
#include <stdlib.h>
int a[2], dp[1000005];
int main() {
    int a[2], ans = 0;
    scanf("%d%d", &a[0], &a[1]);
    int n = a[0] * a[1];
    dp[a[0]] = dp[a[1]] = 1;
    for (int i = 0; i < 2; i++)
        for (int j = a[i]; j <= n; j++)
            dp[j] += dp[j - a[i]];
    for (int i = n; !ans && i; i--)
        if (!dp[i])
            ans = i;
    printf("%d\n", ans);
    return 0;
}
