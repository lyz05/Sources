program B;
const	maxnn=10;
var	i,j,k,m,n,t,tmp:longint;
	a:array[1..maxnn] of boolean;
begin
	randomize;
	t:=10;
	writeln(t);
	for i:=1 to t do begin
		n:=random(10)+1;
		writeln(n);
		for j:=1 to n do 
		begin
			tmp:=random(maxnn)+1;
			//while a[tmp] do tmp:=random(maxnn)+1;
			//a[tmp]:=true;
			write(tmp,' ');
		end;
		writeln;
	end;
end.
program B;
const	a:array[0..1] of string=('BORROW','RETURN');
var	i,j,k,m,n,t:longint;
begin
	randomize;
	n:=300000;
	m:=300000;
	writeln(n,' ',m);
	for i:=1 to m do begin
		t:=random(2);
		writeln(a[t],' ',random(300000)+1,' ',random(1000000000)+1);
	end;
end.
program A;
var	i,j,k,m,n,t:longint;
begin
	randomize;
	n:=1000000;
	m:=1000000;
	writeln(n,' ',m);
	for i:=1 to m do writeln(random(n)+1,' ',random(n)+1);
end.
