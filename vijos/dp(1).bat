@echo off
:loop
data.exe>data.in
	echo running std.exe
		set time1=%time:~9,2%
			std.exe<data.in>std.out
		set time2=%time:~9,2%
	set /a time3=%time2%-%time1%
	echo runnning time %time3% ms

	echo running me.exe
		set time1=%time:~9,2%
			1901.exe<data.in>my.out
		set time2=%time:~9,2%
	set /a time3=%time2%-%time1%
	echo runnning time %time3% ms
fc std.out my.out

if not errorlevel 1 goto loop
::pause
::goto loop

