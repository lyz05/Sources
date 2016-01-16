program C;
var	n,m,k,i,j:longint;
begin
	randomize;
	n:=random(1000)+1;
	m:=random(1000)+1;
	//n:=5;m:=10;
	writeln(n,' ',m);
	for i:=2 to n do begin
		writeln(i,' ',random(i-1)+1,' ',random(1000)+1);
	end;

end.

program B;
var	n,m,k,i,j,x,y,z:longint;
	a:array[1..100,1..100] of longint;
begin
	randomize;
	n:=random(100)+1;
	m:=n*(n-1) div 2-random(n);
	//n:=5;m:=8;
	writeln(n,' ',m);
	for i:=1 to m do begin
		x:=random(n)+1;y:=random(n)+1;z:=random(100)+1;
		while (x=y) or (a[x][y]<>0) do begin 
			x:=random(n)+1;y:=random(n)+1;z:=random(100)+1;
		end;
		a[x][y] := z;a[y][x] := z;
		writeln(x,' ',y,' ',z);
	end;
	k:=random(1000);
	//k:=2;
	writeln(k);
	for i:=1 to k do begin
		x:=random(n)+1;y:=random(n)+1;
		while (x=y) do begin x:=random(n)+1;y:=random(n)+1; end;
		writeln(x,' ',y);
	end;

end.
program A;
var	n,m,k,i,j:longint;
begin
	randomize;
	k:=random(5);
	for j:=1 to k do begin
		n:=random(10000)+1;
		m:=random(100000)+1;
		//n:=5;m:=10;
		writeln(n,' ',m);
		for i:=1 to m do begin
			writeln(random(n),' ',random(n),' ',random(10000)+1);
		end;
	end;
	writeln('0 0');
end.
