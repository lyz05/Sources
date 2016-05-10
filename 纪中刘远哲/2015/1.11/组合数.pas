var	n,m,i:longint;
function jc(x:longint):int64;
var	i:longint;
begin
	jc:=1;
	for i:=2 to x do jc:=jc*i;
end;
begin
	readln(m,n);
	writeln(jc(m) div (jc(n)*jc(m-n)));
end.
