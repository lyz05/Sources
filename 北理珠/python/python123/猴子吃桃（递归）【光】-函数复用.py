def f(n):
    ######################
    # 补充你的代码
    if n == 10:
        return 1
    else:
        return 2 * (f(n+1)+1)

    ######################


print(f(1))

# f(10) = 1
# f(1)  = n-(n/2+1)
# f(2)  = f(1)-f(1)/2+1
# f2*(f(2)-1) = f(1)