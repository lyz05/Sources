@echo off
:loop
	data.exe>data.in
	::std.exe<data.in>std.out
	watchdogs.exe<data.in>my.out
fc std.out my.out
pause
goto loop
::if %errorlevel%=0 goto loop
::pause
