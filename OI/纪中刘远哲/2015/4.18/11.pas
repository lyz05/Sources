const	maxy=1000000;mo=10000;
var	i,j,k,m,n,t,x,y,ans:longint;
	f:array[1..maxy] of longint;
procedure prepar;
var	i:longint;
begin
	f[1]:=1;f[2]:=1;
	for i:=3 to maxy do f[i]:=(f[i-1]+f[i-2]) mod mo;
end;
begin
	assign(input,'1.in');reset(input);
	//assign(output,'.out');rewrite(output);

	prepar;
	readln(t);
	while t>0 do begin
		ans:=0;
		readln(x,y);
		for i:=x to y do ans:=(ans+f[i]) mod mo;
		writeln(ans);
		dec(t);
	end;
end.
