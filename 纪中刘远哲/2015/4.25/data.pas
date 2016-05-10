var	i,m,n,j:longint;
begin
	randomize;
	n:=200000;
	writeln(n);
	for i:=1 to n do writeln(random(100)+1,' ',random(10)+10);
end.
