program p2;
const	maxn=40;
var	i,j,k,m,n,t:longint;
	f:array[0..maxn] of longint;
begin
	f[1]:=1;f[2]:=1;
	for i:=3 to maxn do f[i]:=f[i-1]+f[i-2];
	randomize;
	t:=random(30)+1;
	writeln(t);
	for j:=1 to t do begin
		n:=random(20)+20;
		writeln(n,' ',random(f[n])+1);
	end;
	
end.
program p1;
const	maxn=100;
var	i,j,k,m,n:longint;
	f:array[0..maxn] of longint;
begin
	randomize;
	readln(n);
	f[1]:=1;f[2]:=1;
	for i:=3 to n do f[i]:=f[i-1]+f[i-2];
	for i:=1 to n do f[0]:=f[0]+f[i];
	writeln(f[n]);
	for j:=1 to f[n] do writeln(n,' ',j);
	
end.
