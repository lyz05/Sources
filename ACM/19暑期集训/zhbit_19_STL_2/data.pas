var i,n,T:longint;
begin
	randomize;
	T:=random(100)+1;
	for i:=1 to T do begin
		n:=random(100)+1;
		m:=random(n);
		writeln(n,' ',m);
		for i:=1 to n do write(random(9)+1,' ');
		writeln;
	end;
	writeln(0);
end.