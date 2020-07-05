#删除下划线，在对应位置上填写代码
#不允许修改其他代码
n = input()
nums = n.split(',')
s = 0
for i in nums:
    s += eval(i)
print(s)