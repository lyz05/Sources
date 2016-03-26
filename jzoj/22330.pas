var	i,j,n,m:longint;
	a:array[0..10000] of integer;
begin
	//readln(n);
for n:=1 to 100 do begin
fillchar(a,sizeof(a),0);
        a[0]:=1;
     for i:=1 to n do begin
		inc(a[1]);
		for j:=1 to a[0] do
			if a[j]=3 then begin
				a[j]:=1;
				inc(a[j+1]);
				if j=a[0] then a[0]:=j+1;
			end else break;
     end;
	for i:=a[0] downto 1 do
		if a[i]=1 then write(4) else write(7);
        writeln;
end;
end.
