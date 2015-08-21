var	i,j,k,m,n;longint;
	s:array[1..maxn,1..] of string;
begin
	readln(n);
	for i:=1 to n do readln(x[i],y[i]);
	i:=1;
	while not eof do begin
		readln(s);
		inc(i);
	end;
	m:=i-1;
	i:=1;
	while i<=m do begin
		case s[i,1] of
			'T':
			'S':
			'R':
			'L':begin
				if s[i,6]
				for j:=i+1 to m do 
					if s[j,1]='E' then r:=j-1;
			end;
		end;	
	end;
end.
