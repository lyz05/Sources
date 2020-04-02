print("他说:\"最近的天气很舒服呢 \\ 是不是！\"")
print("他说:'最近的天气很舒服呢 \\ 是不是！'")
print("你好~~\n靓女靓仔~~~")
string = 'Hello python'
print(string[4]    )
print(string[-8]   )
print(string[0:7]  )
print(string[-6:-1])
print(string[5:-2] )
print(string[:4]   )
print(string[:-3]  )
print(string[4:]   )
print(string[-4:]  )
print(string[::-1] )

str1 = 'Python'
str2 = 'is the 非常好!!'
string = str1 + str2
print(string)
print(str1 * 3                   )
print('P' in str1                )
print('p' in str1                )
print(len(string)                )
print(string.strip('!')         )
print(string.split('th')         )
str3 = ','
print(str3.join(string)          )
print(string.find('th')          )
print(string.replace('Py','pY')  )
print(string.upper()             )
print(string.lower()             )
print(string.islower()           )
print(string.endswith('!')      )
print(string.startswith('ppy')   )
print(string.count('th')         )
print(str1.zfill(10)             )
print(str1.center(20,'*')        )

print(str(1.2+4.6))

print(chr(455))
print(ord('#'))
print(hex(455))
print(oct(455))

string = "Hello"
num = 123456.789
print("你好对应的英文是：{:20}".format(string)   )
print("你好对应的英文是：{:>20}".format(string)  )
print("你好对应的英文是：{:^20}".format(string)  )
print("你好对应的英文是：{:*^20}".format(string) )
print("你好对应的英文是：{:2}".format(string)    )
print("你好对应的英文是：{:.2}".format(string)   )

print("数字的对应显示是：{:.2f}".format(num)     )
print("数字的对应显示是：{:,}".format(num)       )
print("数字的对应显示是：{:@^20,.1f}".format(num))
print("数字的对应显示是：{:,.2f}".format(num)    )

num = 15
print("数字的二进制显示是：{:b}".format(num)      )
print("数字的十进制显示是：{:d}".format(num)      )
print("数字的八进制显示是：{:o}".format(num)      )
print("数字的十六进制大写显示是：{:X}".format(num)   )
print("数字的十六进制小写显示是：{:x}".format(num)   )

print("数字的百分制显示是：{:%}".format(num)      )
print("数字的百分制显示是：{:.2%}".format(num)    )
print("数字的百分制显示是：{:e}".format(num)      )
