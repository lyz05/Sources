const	maxn=3000000+5;oo=1000000000;
var	i,j,k,m,n,l,r:longint;
	a,f,g,s,id:array[1..maxn] of longint;
begin
	assign(input,'b.in');reset(input);

	readln(n);
	for i:=1 to n do read(a[i]);

	l:=1;r:=1;s[1]:=oo;id[1]:=0;
	for i:=1 to n do begin
		while (l<r) and (s[r]<a[i]) do dec(r);
		f[i]:=id[r];
		inc(r);
		s[r] := a[i];
		id[r] := i;
	end;

	l:=1;r:=1;s[1]:=oo;id[1]:=n+1;
	for i:=n downto 1 do begin
		while (l<r) and (s[r]<=a[i]) do dec(r);
		g[i]:=id[r];
		inc(r);
		s[r]:=a[i];
		id[r]:=i;
	end;
	for i:=1 to n do begin
		write(int64(g[i]-i)*int64(i-f[i]),' ');
	end;

end.
