clc,clear;
a = load('a.txt');
b = load('b.txt');
c = a;
anss = a;
for i=3:1:15
    c = c*b;
    anss(i)=c(1);
end
anss
%1 1 2 3 5 8 13 21
%1 2 3 4 5 6 7  8