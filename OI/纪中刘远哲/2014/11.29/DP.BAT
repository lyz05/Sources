@echo off
:loop
	data.exe>data.in
        2.exe<data.in>me1.out
        ::22.exe<data.in>me2.out
::fc "ME1.out" "ME2.out"
pause
goto loop
