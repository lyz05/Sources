uses	math;
const	maxn=500+1;
var	n,n1,n2:longint;
	f,g:array[0..maxn,0..maxn] of double;
	q,c:array[0..maxn,1..2] of longint;
	val:array[0..maxn,1..2] of double;
	p:array[0..maxn] of double;
procedure init;
var	i:longint;
begin
	readln(n,n1,n2);
	for i:=1 to n do 
		readln(q[i,1],c[i,1],q[i,2],c[i,2]);
end;
procedure qsort(l,r:longint);
var	i,j:longint;
	m:double;
begin
	i:=l;j:=r;m:=p[(l+r)>>1];
	repeat
		while p[i]>m do inc(i);
		while p[j]<m do dec(j);
		if i<=j then begin
			p[0]:=p[i];p[i]:=p[j];p[j]:=p[0];
			val[0]:=val[i];val[i]:=val[j];val[j]:=val[0];
			inc(i); dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
procedure main;
var	i,j:longint;
	l,r,mid:int64;
	ans,sum,v:double;
begin
	l:=0;r:=2000000000000;
	while l<=r do begin
		mid := (l+r)>>1;
		v := mid / 1000000000;
		for i:=1 to n do begin
			val[i,1]:=q[i,1]-c[i,1]*v;
			val[i,2]:=q[i,2]-c[i,2]*v;
			p[i]:=val[i,1]-val[i,2];
		end;
		qsort(1,n);
		for i:=0 to n+1 do
			for j:=0 to n+1 do begin
				f[i,j]:=-9999999999;g[i,j]:=f[i,j];
			end;
		f[0,0]:=0;
		for i:=0 to n-1 do begin
			f[i+1]:=f[i];
			for j:=0 to i do
				f[i+1,j+1]:=max(f[i+1,j+1],f[i,j]+val[i+1,1]);
		end;
		g[n+1,0]:=0;
		for i:=n+1 downto 2 do begin
			g[i-1]:=g[i];
			for j:=0 to n+1-i do
				g[i-1,j+1]:=max(g[i-1,j+1],g[i,j]+val[i-1,2]);
		end;
		ans:=-99999999;
		for i:=n1 to n-n2 do 
			ans:=max(ans,f[i,n1]+g[i+1,n2]);
		if ans>=0 then begin
			sum:=v;
			l:=mid+1;
		end else r:=mid-1;
	end;
	writeln(sum:0:6);
end;
begin
	assign(input,'love.in');assign(output,'love.out');
	reset(input);rewrite(output);
	init;
	main;
	close(input);close(output);
end.
