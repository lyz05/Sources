var	i,j,k,m,n,cnt,ans:longint;
	x:double;
begin
	//assign(input,'1.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n);
	ans:=0;
	for i:=1 to n do begin
		readln(x,cnt);
		for j:=1 to cnt do begin
			ans:=ans xor trunc(x*j);
		end;
	end;
	writeln(ans);
end.
