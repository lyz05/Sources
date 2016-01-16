@echo off
:loop
	data.exe>data.in
	1121.exe<data.in>1.out
	11210.exe<data.in>11.out
fc "1.out" "11.out"
if not errorlevel 1 goto loop
pause
goto loop