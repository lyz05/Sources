var i,j,k,m,n,len,T:longint;
	p:boolean;
procedure work;
var now:longint;
begin
	len:=random(400)+1;
	now:=random(len);
	for i:=1 to len do begin
		write(random(10));
		if (now=i) then write('.');
	end;
end;
begin
	randomize;
	T:=random(10)+1;
	for j:=1 to T do begin
		work;
		write(' ');
		work;
		writeln;
	end;
end.