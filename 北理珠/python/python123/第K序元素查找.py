nums = eval(input())
k = eval(input())
nums.sort(reverse=True)
print(nums[k-1])