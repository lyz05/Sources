var n,m,i,j:longint;
begin
	randomize;
	n:=random(100)+50000;
	writeln(n);
	for i:=1 to n do writeln(random(10),' ',random(10000));
end.
