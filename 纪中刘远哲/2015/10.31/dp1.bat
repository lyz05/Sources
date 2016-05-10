@echo off
:loop
	data.exe>data.in
	1.exe<data.in
	echo .............
	echo.
goto loop