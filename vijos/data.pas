var	i,j,k,m,n:longint;
begin
	randomize();
	n:=10;
	writeln(n);
	for i:=1 to 3 do
	begin
		for j:=1 to n do write(chr(random(26)+ord('a')));
		writeln;	
  	end;
end.
