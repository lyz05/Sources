def getNum():
    list = []
    while True:
        s = input()
        if (s==''):
            return list
        list.append(s)

print(getNum())