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
