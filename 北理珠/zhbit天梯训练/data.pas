var	i,j,n,g,k:longint;
begin
	randomize;
	n:=random(100)+1;
	g:=random(40)+60;
	k:=random(n);
	writeln(n,' ',g,' ',k);
	for i:=1 to n do begin
		for j:=1 to random(10)+1 do write(chr(ord('a')+random(26)));
		writeln(' ',random(100)+1);
	end;
end.