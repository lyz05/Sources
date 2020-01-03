@echo off  
:loop  
    datamaker   #数据生成器  rand.exe  data.in  这里的大于符号，小于符号为重定向符号
    std      #标准程序   std.exe  data.in  std.out
    myprogram   #my.exe  data.in  my.out   我的程序
    fc ans.out std.out    比较两个程序的输出是否一致，一致则返回0
if not errorlevel 1 goto loop  
pause  
goto loop
#最后上边的 内容 保存为.bat文件
#rand.exe  std.exe  my.exe 以及windows下的这个 .bat文件放在同一个目录下