var	i,j:longint;
begin
	writeln('31 60');
	for j:=1 to 2 do writeln('1 3');
	for i:=3 to 30 do 
		for j:=1 to 2 do writeln(i,' ',i+1);
	for j:=1 to 2 do writeln('31 2');
end.
