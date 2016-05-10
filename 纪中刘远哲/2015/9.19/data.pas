program A;
var	i,j,k,m,n,t:longint;
begin
	n:=100000;
	m:=100000;
	k:=100000;
	writeln(n,' ',m,' ',k);
	for i:=1 to m do writeln(random(n)+1,' ',random(n)+1);
end.

var	i,j,k,m,n,kind:longint;
	a:array[1..3] of string=('Insert','Add','Query');
begin
	randomize;
	n:=random(1000)+1;
	n:=5;
	writeln(n);
	for i:=1 to n do write(random(1000),' ');
	writeln;
	m:=random(1000)+1;
	m:=3;
	writeln(m);
	for i:=1 to m do begin
		kind:=random(2)+2;
		k:=random(n)+1;
		write(a[kind],' ',k,' ',k+random(n-k));
		if kind = 2 then writeln(' ',random(n))
		else writeln;
	end;
end.
var	i,j,k,m,n:longint;
begin
	randomize;
	n:=3000;
	writeln(n);
	for i:=1 to n do begin
		writeln(random(1000000000),' ',random(1000000000));
	end;
end.
