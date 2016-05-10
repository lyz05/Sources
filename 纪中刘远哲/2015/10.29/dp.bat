@echo off
:loop
	data.exe>data.in
	4.exe<data.in>1.out
	44.exe<data.in>11.out
fc "1.out" "11.out"
if not errorlevel 1 goto loop
pause
goto loop