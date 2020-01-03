var i,j,n,m:longint;
begin
	assign(output,'0.in');rewrite(output);
	randomize;
	n:=random(10000);
	writeln(n);
	for i:=1 to n do write(random(1048576),' ');
	writeln;
	close(output);
end.
