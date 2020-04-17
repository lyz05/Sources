import sys
fp = open("G.in", "r")
sys.stdin = fp
while True:
    try: 
        n = eval(input())
    except:
        break
    i = 0
    calc = 0
    while calc<=1e18:
        i += 1
        calc = pow(i,i)
        if (calc>n):
            break
    print(i-1)