var	i,j,k,m,n,x,y,a,b:longint;
procedure exgcd(a,b:longint;var	x,y:longint);
var	x1,y1:longint;
begin
	if b=0 then begin
		x:=1 div a;
		y:=0;
		exit;
	end;
	exgcd(b,a mod b,x1,y1);
	x:=y1;
	y:=x1-a div b*y1;
end;
begin
	readln(a,b);
	exgcd(a,b,x,y);
	x:=x mod b;
	while x<0 do x:=x+b;
	writeln(x);
end.
