n = eval(input())
for a in range(2,n+1):
    for b in range(2,n+1):
        for c in range(b,n+1):
            for d in range(c,n+1):
                if (pow(a,3)==pow(b,3)+pow(c,3)+pow(d,3)):
                    print("Cube = {},Tripe = ({},{},{})".format(a,b,c,d))