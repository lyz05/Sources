program q1;
var	i,j,k,m,n:longint;
begin
	randomize;
	n:=random(30)+1;
	m:=random(30)+1;
	k:=random(n*m)+1;
	writeln(n,' ',m,' ',k);
	for i:=1 to k do begin
		writeln(random(n),' ',random(m),' ',random(300));
	end;
end.
