import random

list = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']
n = eval(input())
random.seed(n)
random.shuffle(list)
print(list)
