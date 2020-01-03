var	i,j,k,m,n:longint;
	ans:qword;
function jc(x:longint):qword;
begin
	jc:=1;
	for i:=2 to x do jc:=jc*i;
end;
function mi(x,y:longint):qword;
begin
	mi:=1;
	for i:=1 to y do mi:=mi*x;
end;
function put(x:qword):ansistring;
begin
	str(x,put);
	for i:=1 to 120-length(put) do begin
		put:='0'+put;
	end;
	writeln(put);
	halt;
end;
begin
	readln(n);
	if n<17 then put(0);
	ans:=jc(n-1);
	ans:=ans*mi(17,n-17);
	put(ans);
end.
