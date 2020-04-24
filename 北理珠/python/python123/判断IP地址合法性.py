flag = True
s = input()
nums = s.split('.')
if len(nums) !=4:
    flag = False
for num in nums:
    try:
        num = eval(num)
        if num < 0 or num > 255:
            flag = False
    except:
        flag = False

if flag:
    print('Yes')
else:
    print('No')