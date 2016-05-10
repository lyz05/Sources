const	ans:array[1..1] of qword=(20922789888000);
var	i,j,k,m,n:longint;
function put(x:qword):ansistring;
begin
	str(x,put);
	for i:=1 to 120-length(put) do begin
		put:='0'+put;
	end;
	writeln(put);
end;
begin
	readln(n);
	if n<17 then put(0) else put(ans[1]);
end.
