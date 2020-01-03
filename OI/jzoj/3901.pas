var	i,j,k,m,n,x:longint;
	h,l,r,a,b,dep:array[1..maxn] of longint;
	ans:int64;
begin
	readln(n);
	for i:=1 to n do begin
		readln(x);
		h[x]:=i;
	end;
	for i:=1 to n do begin
		l[h[i]]:=h[i-1];
		r[h[i-1]]:=h[i];
	end;
	l[0]:=0;r[0]:=0;
	for i:=n downto 1 do begin
		a[i]:=l[i];
		b[i]:=r[i];
		l[r[i]]:=l[i];
		r[l[i]]:=r[i];
	end;
	dep[0]:=0;dep[1]:=0;
	for i:=2 to n do begin
		dep[i]:=max(dep[a[i]],dep[b[i]])+1;
	end;
	for i:=1 to n do begin
		inc(ans,dep[i]);
		writeln(ans);
	end;
end.
