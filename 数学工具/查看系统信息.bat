@echo off
echo ��ʼ������Ϣ
c:\windows\system32\systeminfo.exe
choice /c yn /m "�Ƿ���Ϣ������Ӳ��"
if errorlevel 2 goto print
if errorlevel 1 goto end

:print
c:\windows\system32\systeminfo.exe>c:\1.txt
goto end
:end
echo ��лʹ��
pause 