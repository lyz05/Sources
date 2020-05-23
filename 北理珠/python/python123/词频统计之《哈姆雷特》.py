flag = input()
if flag == " ":
    n = 10
else:
    n = 1
black_list = '!"#$%&()*+,-./:;<=>?@[\\]^_‘{|}~'
dict = {}
f = open("hamlet.txt", "r")
txt = f.read().lower()
f.close()
for ch in black_list:
    txt = txt.replace(ch, ' ')
for item in txt.split():
    if item not in dict:
        dict[item] = 1
    else:
        dict[item] += 1
ans = list(dict.items())
ans.sort(key=lambda x: x[1], reverse=True)
for i in range(n):
    word, count = ans[i]
    print("{:<10},{:>5}".format(word, count))
