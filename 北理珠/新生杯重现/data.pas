var	i,j,T,len:longint;
begin
	randomize;
	T:=random(20)+1;
	writeln(T);
	for i:=1 to T do begin
		len:=random(100)+1;
		//len:=random(10)+1;
		for j:=1 to len do write(random(10));
		write(' ');
		len:=random(100)+1;
		//len:=random(10)+1;
		for j:=1 to len do write(random(10));
		writeln;
	end;
end.