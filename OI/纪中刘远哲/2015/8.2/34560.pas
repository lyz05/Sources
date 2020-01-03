var	n,ans:longint;
	x:qword;
function jc(x:longint):qword;
var	i:longint;
begin
	jc:=1;
	for i:=2 to x do jc:=jc*i;
end;
function fj(x:qword):longint;
var	i:longint;
begin
	fj:=0;
	for i:=1 to trunc(sqrt(x)) do begin
		if x mod i=0 then 
			if (x div i<>i) then inc(fj,2) else inc(fj);
	end;
end;
begin
	readln(n);
	x:=jc(n);
	x:=x*x;
	ans:=fj(x);
	writeln(ans);
end.

