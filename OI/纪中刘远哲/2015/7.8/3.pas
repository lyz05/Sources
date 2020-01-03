var	i,j,m,n,x,y,v1,v2:longint;
begin
	readln(n,m);
	for i:=1 to m do begin
		readln(x,y,v1,v2);
		add(x,y,v1);
		add(y,x,v2);
	end;
end.
