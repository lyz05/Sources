var	s:ansistring;			//change
	next:array[1..maxn] of longint;
	i,len:integer;
begin
	assign(input,'4022.in');reset(input);
	assign(output,'4022.out');rewrite(output);

	readln(s);
	len:=length(s);
	next[len]:=-1;
	for i:=1 to len-1 do next[i]:=i+1;
	
	for l:=1 to len div 2 do begin
		x:=1;y:=1;
		
		while i<>0 do begin
			s[i]
			i:=next[i];
		end;
	end;	
	writeln(s);
end.
