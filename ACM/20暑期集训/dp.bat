@echo off
C:\FPC\2.0.4\bin\i386-win32\fpc data.pas
g++ -g 确定比赛名次.cpp -o 确定比赛名次.exe
g++ -g 确定比赛名次1.cpp -o 确定比赛名次1.exe
:loop
	data.exe>data.in
	确定比赛名次.exe<data.in>1.out
	确定比赛名次1.exe<data.in>11.out
fc "1.out" "11.out"
::pause
if not errorlevel 1 goto loop
pause
goto loop