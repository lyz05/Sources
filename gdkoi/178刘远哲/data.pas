var	i,j,k,m,n,c:longint;
begin
	randomize;
	n:=random(1000)+1;k:=random(n)+1;c:=random(1000000000)+1;
	writeln(n,' ',k,' ',c);
	for i:=1 to n do write(random(1000000000),' ');
	writeln;
end.

var	i,j,k,m,n:longint;
begin
	randomize;
	n:=random(100);m:=random(1000);
	writeln(n,' ',m);
	for i:=1 to m do begin
		writeln(random(100)+1,' ',random(100)+1);
	end;
	for i:=1 to n do write(random(1000),' ');
	writeln;
	for i:=1 to n do write(random(1000),' ');
		
end.

var	i,j,k,m,n:longint;
begin
	randomize;
	n:=20;
	k:=n div 2;
	writeln(n,' ',k);
	for i:=1 to n do begin
		writeln(random(99999),' ',random(99999),' ',random(2));
	end;
end.
