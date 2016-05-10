var	m,n,i,j,l,r:longint;
	ch:char;
begin
	randomize;
	//n:=10;m:=20;
	n:=random(100)+1;m:=random(100)+1;
	writeln(n);
	for i:=1 to n do write(random(999999),' ');
	writeln;
	writeln(m);
	for i:=1 to m do begin
		j:=random(3)+1;
		case j of 
			1:CH:='A';
			2:CH:='M';
			3:CH:='Q';
		end;
		write(ch,' ');
		l:=random(n)+1;r:=random(n)+1;
		if l>r then begin
			j:=l;
			l:=r;
			r:=j;
		end;
		if ch='Q' then writeln(random(n)+1) 
			else writeln(l,' ',r,' ',random(9999999));

	end;
end.
