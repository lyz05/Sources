var	i,m,n,x0,a,b,c:longint;
	x:int64;
begin
	//assign(input,'sequence.in');reset(input);
	//assign(output,'sequence.out');rewrite(output);

	readln(x0,a,b,c,n,m);
	x:=x0 mod m;
	for i:=1 to n do begin
		x:=(a mod m*x mod m*x
			mod m+b mod m*x mod m+c) mod m;
		writeln(x);
	end;
	//writeln(x);

	close(input);close(output);
end.
