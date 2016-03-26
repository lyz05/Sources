const	maxn=20;
var	i,j,k,m,n:longint;
	f,g:array[0..maxn] of int64;
function work(s1,t1,s2,t2,n,k:longint):int64;
var	k1,k2,d1:longint;
begin
	if n=0 then exit(0);
	k1:=6-s1-t1;
	k2:=6-s2-t2;
	if k<=f[n-1] then begin
		d1:=s1;
		if s2=d1 then exit(work(s1,k1,s2,t2,n-1,k));
		if k2=d1 then exit(work(s1,k1,t2,s2,n-1,k)+g[n-1]+1);
		if t2=d1 then exit(work(s1,k1,s2,t2,n-1,k)+2*g[n-1]+2);
	end else begin
		d1:=t1;
		if s2=d1 then exit(work(k1,t1,s2,t2,n-1,k-f[n-1]-1));
		if k2=d1 then exit(work(k1,t1,t2,s2,n-1,k-f[n-1]-1)+g[n-1]+1);
		if t2=d1 then exit(work(k1,t1,s2,t2,n-1,k-f[n-1]-1)+2*g[n-1]+2);
	end;
end;
begin
	for i:=1 to 20 do begin
		f[i]:=2*f[i-1]+1;
		g[i]:=3*g[i-1]+2;
	end;
	readln(n,m);
	writeln(work(1,3,1,3,n,m));
end.
