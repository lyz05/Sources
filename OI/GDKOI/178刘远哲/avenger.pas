var	i,j,k,m,n,t,x,l,a:longint;
begin
	assign(input,'avenger.in');reset(input);
	assign(output,'avenger.out');rewrite(output);

	readln(t);
	for i:=1 to t do begin
		readln(x,k,l,a);
		if (k*a>l) and (x=1) then writeln(k*a) else writeln(k*a+1)
	end;

	close(input);close(output);
end.
