var	i,j,k,m,n,T,len:longint;
begin
	randomize;
	T:=random(10)+1;
	writeln(T);
	for i:=1 to T do begin
		len:=random(10)+1;
		for j:=1 to len do 
			if (random(2)=1) then write('+') else write('-');
		writeln;
	end;
end.
