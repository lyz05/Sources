var	i,n,m,k,l:longint;
begin
	randomize;
	n:=random(6)+1;
	k:=1;
	for i:=1 to n do k:=k*26;
	m:=random(k)+1;
	writeln(n,' ',m);
end.