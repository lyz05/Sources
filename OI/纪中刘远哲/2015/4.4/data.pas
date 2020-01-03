var	i,j,k,m,n:longint;
begin
	randomize;
	n:=500;
	for i:=1 to n do begin
		j:=random(2)+1;
		k:=random(26)+1;
		if odd(j) then 
			write(chr(k+64))
		else	write(chr(k+96));	
	end;
	writeln;
	writeln(random((n*n)>>2)+1);
end.

begin
	randomize;
	n:=100;
	writeln(n);
	for i:=1 to n do writeln(i);	
end.
