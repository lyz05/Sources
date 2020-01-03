@echo off
:loop
	data.exe>data.in
	1768.exe<data.in>1.out
	17680.exe<data.in>11.out
fc "1.out" "11.out"
::pause
if not errorlevel 1 goto loop
pause
goto loop