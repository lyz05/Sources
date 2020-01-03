@echo off
:loop
	data.exe>data.in
        1.exe<data.in
        ::2.exe<data.in>2.out
::fc "22.out" "2.out"
if not errorlevel 1 goto loop
pause
goto loop
