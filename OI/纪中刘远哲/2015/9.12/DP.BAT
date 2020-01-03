@echo off
:loop
	data.exe>data.in
        3.exe<data.in>3.out
        33.exe<data.in>33.out
fc "3.out" "33.out"
if (%errorlevel% == 0) goto loop
pause
goto loop
