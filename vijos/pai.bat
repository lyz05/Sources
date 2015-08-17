@echo off
:Ac
Data
B
A
fc s.out a.out
if not errorlevel 1 goto Ac
pause
goto Ac