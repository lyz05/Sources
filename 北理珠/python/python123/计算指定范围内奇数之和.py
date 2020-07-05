n = eval(input())
sum = 0
for i in range(n, n + 100):
    if i % 2 == 1:
        sum += i
print(sum)
