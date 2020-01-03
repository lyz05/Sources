var	i,j,k,m,n:longint;
	ans:int64;
begin
	readln(n,m);
	if m=3 then begin
		ans:=1;
		for i:=1 to n do ans:=ans*2;
		dec(ans);
		writeln(ans);
	end;
end.

