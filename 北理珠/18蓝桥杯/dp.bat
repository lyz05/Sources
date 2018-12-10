@echo off
:loop
	data.exe>data.in
	5.exe<data.in>5.out
	type 5.out
pause
goto loop