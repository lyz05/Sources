m = eval(input())
k = 0
ans = 0
while (abs(pow(-1, k) * 1 / (2 * k + 1)) >= m):
    tmp = pow(-1, k) * 1 / (2 * k + 1)
    ans += tmp
    k += 1
print("{:.6f}".format(ans * 4))
