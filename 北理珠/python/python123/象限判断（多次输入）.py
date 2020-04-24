while True:
    try:
        x = eval(input())
        y = eval(input())
    except:
        print("EXIT")
        break
    else:
        if x == 0 or y == 0:
            print("x={}\ny={}".format(x, y))
        elif x > 0 and y > 0:
            print("Q1")
        elif x < 0 and y > 0:
            print("Q2")
        elif x < 0 and y < 0:
            print("Q3")
        else:
            print("Q4")
