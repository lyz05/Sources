const oula=0.57721566490153286060651209;
var	i,j,k,m,n:longint;
	ans:extended;	
begin
	readln(n);
	if n<=10000000 then
		for i:=1 to n do ans:=ans+1/i
	else ans:=ln(n)+oula;
	writeln(n*ans:0:0);
end.
