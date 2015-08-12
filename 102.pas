var n,m,c,i,j:longint;
    a,f:array[0..1000001] of int64;
function min(x,y:int64):int64;
begin
	if x<y then exit(x) else exit(y);
end;
procedure qsort(x,y:longint);
var i,j,k:longint;
begin
	i:=x;j:=y;
	k:=a[(i+j) div 2];
	while i<=j do begin
		while a[i]<k do inc(i);
		while a[j]>k do dec(j);
		if i<=j then begin
			a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
			inc(i);dec(j);
		end;
	end;
	if i<y then qsort(i,y);
	if x<j then qsort(x,j);
end;
begin
	readln(n,m,c);
	for i:=1 to n do read(a[i]);
	qsort(1,n);
	for i:=m to n do f[i]:=sqr(a[i]-a[1])+c;
	for i:=2*m to n do for j:=m to i-m do f[i]:=min(f[i],f[j]+sqr(a[i]-a[j+1])+c);
	writeln(f[n]);
end.
