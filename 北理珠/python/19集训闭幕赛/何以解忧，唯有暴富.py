import math
import sys

try:
    lines = sys.stdin.read().splitlines()
    for line in lines:
        n, m = map(int,line.split())
        ans = math.ceil(m/n)
        print(ans)
except:
    pass