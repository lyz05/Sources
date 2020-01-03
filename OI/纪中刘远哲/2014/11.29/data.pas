var	i,j,m,n:longint;
begin
	randomize;
	n:=1000000;
	m:=100;
	writeln(n,' ',m);
	for i:=1 to n do write(random(100000),' ');
	writeln;
	for i:=1 to m do write(random(100000000),' ');
	writeln;
end.
