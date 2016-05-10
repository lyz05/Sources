const	mo=1<<17-1;
var	i,j,k,m,n,ans,t:longint;
function jc(x:longint):longint;
var	i:longint;
begin
	jc:=1;
	for i:=2 to x do jc:=jc*i;
end;
function gcd(x,y:longint):longint;
var	i:longint;
begin
	while y<>0 do begin
		i:=x mod y;
		x:=y;
		y:=i;
	end;
	exit(x);
end;
begin
	assign(input,'1.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(t);
	while t>0  do begin
		ans:=0;
		readln(n,m);
		m:=jc(m);
		for i:=1 to jc(n) do begin
			if gcd(i,m)=1 then inc(ans);
		end;
		writeln(ans mod mo);
		dec(t);
	end;
end.
