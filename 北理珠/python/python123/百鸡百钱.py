for i in range(100):
    for j in range(100-i):
        k = 100-i-j
        if 5*i+3*j+k/3==100:
            print("{} {} {}".format(i,j,k))