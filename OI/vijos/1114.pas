var	i,j,k,m,n:longint;
	s:ansistring;
function make(l,r:longint):char;
var	mid:longint;
	x,y:char;
begin
	if l=r then 
		if s[l]='0' then exit('B') else exit('I');
	mid:=(l+r)>>1;
	x:=make(l,mid);
	write(x);
	y:=make(mid+1,r);
	write(y);

	if (x=y) then begin
		if (x='I') then exit('I') else
		       if (x='B') then exit('B') else exit('F');
	end else exit('F');
end;
begin
	readln(n);
	readln(s);
	writeln(make(1,1<<n));
end.
