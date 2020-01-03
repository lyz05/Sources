uses	math;
const	maxn=100+5;
var	i,j,k,m,n,ans,last:longint;
	a,f,g,h:array[1..maxn] of longint;
begin
	readln(n);
	for i:=1 to n do read(a[i]);
	f[1]:=1;
	last:=a[1];
	for i:=2 to n do begin
		if last>=a[i] then f[i]:=1;
		last:=min(last,a[i]);
	end;

	g[n]:=1;
	last:=a[n];
	for i:=n-1 downto 1 do begin
		if last>=a[i] then g[i]:=1;
		last:=min(last,a[i]);
	end;

	
	for i:=2 to n do begin
		last:=0;
		for j:=1 to i-1 do
			if (a[j]<a[i]) then last:=max(last,f[j]);
		f[i]:=last+1;
	end;
	for i:=n-1 downto 1 do begin
		last:=0;
		for j:=i+1 to n do 
			if a[i]>a[j] then last:=max(last,g[j]);
		g[i]:=last+1;
	end;
	ans:=maxlongint>>1;
	for i:=1 to n do 
		//if (f[i]<>1) and (g[i]<>1) then
			ans:=min(ans,n-(f[i]+g[i]-1));
	writeln(ans);
end.
