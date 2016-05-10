program B;
var	i,j,k,m,n,t,p:longint;
	//a:array[1..100000] of longint;
begin

	randomize;
	n:=3000000;
	writeln(n);
	for i:=1 to n do begin
		write(random(100000000),' ');
	end;
	writeln;
end.
program c;
var	i,j,k,t,p:longint;
	n,m:int64;
	a:array[1..100000] of string;
begin
	a[1] := 'count';
	a[2] := 'add';
	randomize;
	n:=1000;
	m:=1000;
	writeln(n,' ',m);
	for i:=1 to n do write(random(10000),' ');
	writeln;
	for i:=1 to m do begin
		a[3]:=a[random(2)+1];
		write(a[3],' ',random(n),' ',random(n),' ');
		if a[3]=a[2] then writeln(random(1000)) else writeln;
	end;
end.

program A;
var	i,j,k,t,p:longint;
	n,m:int64;
	//a:array[1..100000] of longint;
begin
	randomize;
	n:=random(1000000000000-100000000000)+100000000000;
	m:=random(1000000000000-100000000000)+100000000000;
	writeln(n,' ',m);
	writeln;
end.

program A;
var	i,j,k,m,n,t,p:longint;
	//a:array[1..100000] of longint;
begin
	randomize;
	n:=5000000;
	for i:=1 to n do begin
		write(chr(ord('a')+random(26)));
	end;
	writeln;
end.
program B;
var	i,j,k,m,n,t,p:longint;
	a:array[1..100000] of longint;
begin
	randomize;
	n:=100000;
	writeln(n);
	for i:=1 to n-1 do begin
		writeln(random(n)+1,' ',random(n)+1);
	end;
end.
program C;
var	i,j,k,m,n,t,p:longint;
begin
	randomize;
	T:=random(1000);
	writeln(T);
	for i:=1 to T do begin
		writeln(random(1000));
	end;
end.
program B;
var	i,j,k,m,n,t,p:longint;
begin
	randomize;
	T:=2;
	writeln(T);
	for i:=1 to T do begin
		n:=random(10);
		m:=random(10);
		p:=random(10000);
		writeln(n,' ',m,' ',p);
		for j:=1 to n+m do 
			writeln(random(100),' ',random(100),' ',random(100));
	end;
end.

program A;
var	i,j,k,m,n,t,q:longint;
begin
	randomize;
	T:=10;
	writeln(T);
	for j:=1 to T do begin
		n:=20000;
		m:=100000;
		q:=5000;
		//n:=20;m:=5;q:=10;
		writeln(n,' ',m,' ',q);
		for i:=1 to m do 
			writeln(random(n)+1,' ',random(n)+1,' ',random(100000)+1);
		for i:=1 to q do writeln(random(100000)+1);
	end;
end.

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
