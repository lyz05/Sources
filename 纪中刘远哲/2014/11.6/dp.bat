@echo off
:loop
data.exe>data.in
::echo running std
::shooter.exe<data.in>std.out
echo running my
shooter1.exe<data.in>my.out
::fc std.out my.out
pause
goto loop