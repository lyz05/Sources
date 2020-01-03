@echo off  
:loop  
    data.exe>data.in
    1001.exe<data.in>1001.out
    P1001.exe<data.in>P1001.out
    fc 1001.out P1001.out
if not errorlevel 1 goto loop  
pause  
goto loop