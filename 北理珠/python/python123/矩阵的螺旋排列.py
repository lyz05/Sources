def xzjz(m):
    if len(m) == 0:
        return []
    elif len(m) == 1:
        return m[0]
    else:
        a = len(m)
        b = len(m[0])
        c1 = []
        c2 = []
        if b == 1:
            a = []
            for i in m:
                a.append(i[0])
            return a
        for i in range(1, a - 1):
            c1.append(m[i][b - 1])
            c2.append(m[i][0])
        next_m = []
        for j in m[1:-1]:
            m1 = j[1:-1]
            next_m.append(m1)
        return m[0] + c1 + m[a - 1][::-1] + c2[::-1] + xzjz(next_m)
    return xzjz(matrix)


a = eval(input())
print(xzjz(a))
