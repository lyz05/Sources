program A;
var	i,j,k,m,n:longint;
	b:array[1..10000] of longint;
begin
	randomize;
	n:=random(100)+1;
	//n:=5;
	m:=random(n)+1;
	for i:=1 to n+1 do begin
		b[i]:=b[i-1]+random(1000)+1;
	end;
	writeln(n,' ',m,' ',b[n+1]);
	for i:=1 to n do writeln(b[i]);
end.
