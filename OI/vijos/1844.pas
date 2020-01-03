uses	math;
var	i,j,k,m,n,ans,last,now:longint;
	//h:array[1..maxn] of longint;
begin
	readln(n);
	ans:=0;last:=0;
	for i:=1 to n do begin
		read(now);
		inc(ans,now);
		dec(ans,min(last,now));
		last:=now;
	end;
	writeln(ans);
end.
