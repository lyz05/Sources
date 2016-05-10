var	i,j,m,n:longint;
	a:array[1..maxn,1..8] of longint;
	c:array[1..8,0..maxn] of longint;
	//b:array[0..maxn] of longint;
begin
	readln(n,k);
	for i:=1 to n do readln(a[i,1],a[i,2]);
	qsort(1,n);
	m:=maxlongint;
	for i:=1 to n do begin
		//b[i]:=a[i,1];
		inc(c[a[i,2],0]);
		c[a[i,2],c[a[i,2],0]]:=i;
		if c[a[i,2],0]<m then m:=c[a[i,2],0];
	end;
	for i:=m downto 1 do begin
end.
