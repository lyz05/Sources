var	i,j,k,m,n,T:longint;
begin
	randomize;
	T:=random(15);
	//T:=1;
	for k:=1 to T do begin
		m:=random(7)+1;
		n:=random(7)+1;
		writeln(m,' ',n);
		for i:=1 to m do begin 
			for j:=1 to n do 
				write(random(2),' ');
			writeln;
		end;
	end;
end.