@echo off
:loop
	data.exe>data.in
        3922.exe<data.in>me1.out
        EDITOR.exe<data.in>me2.out
fc "ME1.out" "ME2.out"
pause
goto loop
