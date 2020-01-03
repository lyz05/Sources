@echo off
:loop
	data.exe>czl.in
        3.exe>3.out
        33.exe>33.out
fc "3.out" "33.out"
if not errorlevel 1 goto loop
pause
goto loop
