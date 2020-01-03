var	i,j,m,n:longint;
begin
	randomize;
	n:=random(5)+1;m:=random(5)+1;
	writeln(n,' ',m);
	for i:=1 to n do begin
		for j:=1 to m do 
			write(random(10000),' ');
		writeln;
	end;
end.
