import jieba


def alias(word, stdwords):
    for stdword in stdwords:
        if word in stdword:
            return stdword[0]
    return word


aliaswords = [['宝玉', '贾宝玉', '宝二爷'],
              ['贾母', '老太太'],
              ['王熙凤', '熙凤', '凤姐儿', '凤姐', '凤姐姐'],
              ['黛玉', '林黛玉', '林姑娘', '林妹妹'],
              ['宝钗', '薛宝钗', '宝姐姐']]
stopwords = {'什么', '一个', '我们', '那里', '你们', '如今', '说道', '起来', '这里', '知道', '他们', '众人', '姑娘', '一面', '自己', '只见', '太太', '不是',
             '没有', '两个', '怎么', '出来', '不知', '这个', '听见', '这样', '进来', '咱们', '告诉', '就是', '东西', '回来', '只是', '大家', '老爷', '只得',
             '丫头', '这些', '不敢', '出去', '所以', '奶奶', '不过', '的话', '不好', '姐姐'}
with open("红楼梦(utf-8).txt", "r", encoding="utf-8") as f:
    txt = f.read()
words = jieba.lcut(txt)
counts = {}
for word in words:
    if len(word) == 1:
        continue
    else:
        nword = alias(word, aliaswords)
        counts[nword] = counts.get(nword, 0) + 1
for word in stopwords:
    del (counts[word])
items = list(counts.items())
items.sort(key=lambda x: x[1], reverse=True)
#print(items)
for i in range(10):
    word,segment=items[i]
    print('{:<8}{:>6}'.format(word,segment))