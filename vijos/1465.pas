var	i,j,k,m,n:longint;
	a:array[0..32] of longint;
begin
	assign(input,'1465.in');reset(input);
	//assign(output,'.out');rewrite(output);

	while not eof do begin
		readln(n,m);
		write(n,'=');
		while n<>0 do begin
			j:=n mod m;
			if j<0 then begin
				j:=n-((n div m+1)*m);
				n:=n div m+1;
			end else n:=n div m;
			inc(a[0]);
			a[a[0]]:=j;
		end;
		while a[0]>0 do begin
			if a[a[0]]>9 then write(chr(a[a[0]]+55)) 
			else
				write(a[a[0]]);
			dec(a[0]);
		end;
		writeln('(base ',m,')');
	end;
end.
