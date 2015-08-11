var	f:array[1..20000] of double;
	s:array[1..20000] of double;
	n,i:longint;
procedure work(x:longint);
var	i:longint;
begin
	for i:=1 to x do f[x]:=f[x]+f[i];
	f[x] := f[x]/x+1;
end;
begin
	readln(n);
	f[1]:=0;s[1]:=0;
	for i:=2 to n do begin
		f[i]:=(s[i-1]+i)/(i-1);
		s[i]:=s[i-1]+f[i];
	end;
	writeln(f[n]:0:2);
end.
