var	a,b:array[0..3] of longint;
	i,j,tmp:longint;
begin
	for i:=0 to 3 do read(b[i]);
	for i:=0 to 3 do begin
		a[i]:=0;
		for j:=0 to i do begin
			inc(a[i],b[j]);
			inc(b[a[i] mod 4],a[j]);
		end;
	end;
	tmp:=1;
	for i:=0 to 3 do begin
		a[i]:=a[i] mod 10;
		b[i]:=b[i] mod 10;
		tmp:=tmp*(a[i]+b[i]);
	end;
	writeln(tmp);
	
end.
