n = eval(input())
n = n // 2 + 1
for i in range(n):
    print(' ' * (n - i - 1)+'*' * (i * 2 + 1)+' ' * (n - i - 1))
