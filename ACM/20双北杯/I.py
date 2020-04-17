T = eval(input())
for i in range(1,T+1):
	n = eval(input())
	s = input()
	ans = 0
	print("Case #{}:".format(i))
	for i in range(0,n-1):
		if s[i]!=s[i+1]:
			ans += 1
	if ans%2==1:
		ans += 1
	print(ans//2)