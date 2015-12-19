var	i,j,k,m,n:longint;
	x,y,z,x1,y1,x2,y2:longint;
function dis:double;
begin
	dis:=sqrt(sqr(x1-x2)+sqr(y1-y2));
end;
begin
	assign(input,'circle.in');reset(input);
	assign(output,'circle.out');rewrite(output);
	readln(n);
	for i:=1 to n do begin
		readln(x,y,z);
	end;
	readln(x1,y1,x2,y2);
	writeln(dis:0:4);
	close(input);close(output);
end.
