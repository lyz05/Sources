lt = []
for i in range(5):
    lt.append(i)
lt[1] = 6
lt.insert(2,"new")
del lt[0]
for i in range(3):
    del lt[0]
print(0 in lt)
lt.append(0)
print(lt.index(0))
print(len(lt))
print(max(lt))
lt.clear()
#print(lt)