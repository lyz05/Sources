@echo off
C:\FPC\2.0.4\bin\i386-win32\fpc data.pas
g++ -g ȷ����������.cpp -o ȷ����������.exe
g++ -g ȷ����������1.cpp -o ȷ����������1.exe
:loop
	data.exe>data.in
	ȷ����������.exe<data.in>1.out
	ȷ����������1.exe<data.in>11.out
fc "1.out" "11.out"
::pause
if not errorlevel 1 goto loop
pause
goto loop