def sum(n):
    ret = 0
    for i in range(n+1):
        ret += i
    return ret

n=eval(input())
print(sum(n))