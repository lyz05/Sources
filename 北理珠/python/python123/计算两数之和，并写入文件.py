nums = input().split()
target = eval(input())
f = open('result.txt','w')
for i in range(0,len(nums)):
    for j in range(i+1,len(nums)):
        if eval(nums[i])+eval(nums[j])==target:
            print('结果为：{} {}'.format(i,j))
            f.write('结果为：{} {}'.format(i,j))
            f.close()
            exit(0)
print('结果为：Fail')
f.write('结果为：Fail')
f.close()