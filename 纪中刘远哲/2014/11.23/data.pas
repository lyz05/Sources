var	n,m,i,j,k:longint;
begin
	randomize;
	n:=random(20)+2;
	writeln(n);
	for i:=1 to n-1 do begin
		m:=random(2)+1;
		if i<>n-1 then begin
			if m=1 then write('d ',random(10000)) else 
				write('p ',random(200000));
		end else begin
			write('p ',random(5)+1);
		end;
		writeln;
	end;
end.
