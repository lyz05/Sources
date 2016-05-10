program second;
var	i,j,t,len:longint;
begin
	randomize;
	t:=10;
	writeln(t);
	for i:=1 to t do begin
		len:=RANDOM(8)+1;
		len:=20;
		for j:=1 to len do 
			if random(2)=0 then write('.') else write('X');
		writeln;
	end;
end.
