@echo off
:loop
data.exe>data.in
2.exe<data.in>2.out
20.exe<data.in>20.out
fc 2.out 20.out
pause
goto loop
