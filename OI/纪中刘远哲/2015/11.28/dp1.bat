@echo off
:loop
	data.exe>data.in
	count.exe<data.in
	echo .............
	echo.
goto loop