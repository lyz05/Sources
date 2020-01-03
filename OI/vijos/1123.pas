const	maxn=100;
var	i,j,k,m,n,x,y,sum,ans:longint;
	a:array[1..maxn] of longint;
begin
	readln(n);sum:=0;ans:=0;
	for i:=1 to n do begin
		read(a[i]);
		inc(sum,a[i]);
	end;
	sum:=sum div n;
	for i:=1 to n do a[i]:=a[i]-sum;
	for i:=2 to n do begin
		if a[i-1]=0 then continue;
		a[i]:=a[i]+a[i-1];
		a[i-1]:=0;
		inc(ans);
	end;
	writeln(ans);
end.
