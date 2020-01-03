var	i,j,k,m,n:longint;
begin
	readln(n);
	for i:=2 to n do 
		if n mod i=0 then begin
			writeln(n div i);
			break;
		end;
end.
