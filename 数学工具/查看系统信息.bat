@echo off
echo 开始加载信息
c:\windows\system32\systeminfo.exe
choice /c yn /m "是否将信息保存至硬盘"
if errorlevel 2 goto print
if errorlevel 1 goto end

:print
c:\windows\system32\systeminfo.exe>c:\1.txt
goto end
:end
echo 感谢使用
pause 