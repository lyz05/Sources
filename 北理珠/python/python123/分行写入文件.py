file = open('name.txt','w+',encoding='utf-8')
ls = ['180021104890\n','刘远哲\n','18软件工程2班\n']
file.writelines(ls)
file.close()
