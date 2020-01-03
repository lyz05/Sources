var	i,n,j:longint;
	a:array[1..1000] of longint;
begin
	readln(n);
	for i:=1 to n do a[i]:=1;
	for i:=1 to n do begin
		for j:=1 to i div 2 do a[i]:=a[i]+a[j];
	end;
	writeln(a[n]);
end.

