black_list = '!"#$%&()*+,-./:;<=>?@[\\]^_‘{|}~'
dict = {}
with open("hamlet.txt", "r") as f:
    txt = f.read().lower()
for ch in black_list:
    txt = txt.replace(ch, ' ')
for item in txt.split():
    dict[item] = dict.get(item,0)+1
ans = list(dict.items())
ans.sort(key=lambda x: x[1], reverse=True)
for i in range(10):
    word, count = ans[i]
    print("{:<10},{:>5}".format(word, count))
