var i,j,m,n:longint;
	a:array[1..26] of char;
begin
	randomize;
	n:=random(1000)+1;
	writeln(n);
	writeln('bdceafghijklmnopqrstuvwxyz');
	for i:=1 to n do begin
		m:=random(100);
		for j:=1 to m do 
			write(chr(ord('a')+random(26)));
		writeln;
	end;
	
end.