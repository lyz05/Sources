@echo off  
:loop  
    datamaker   #����������  rand.exe  data.in  ����Ĵ��ڷ��ţ�С�ڷ���Ϊ�ض������
    std      #��׼����   std.exe  data.in  std.out
    myprogram   #my.exe  data.in  my.out   �ҵĳ���
    fc ans.out std.out    �Ƚ��������������Ƿ�һ�£�һ���򷵻�0
if not errorlevel 1 goto loop  
pause  
goto loop
#����ϱߵ� ���� ����Ϊ.bat�ļ�
#rand.exe  std.exe  my.exe �Լ�windows�µ���� .bat�ļ�����ͬһ��Ŀ¼��