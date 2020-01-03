@echo off
:loop
	data.exe>data.in
	travel.exe<data.in>1.out
	travel1.exe<data.in>11.out
fc "1.out" "11.out"
if not errorlevel 1 goto loop
pause
goto loop