var	i,j,k,m,n,ans,tot:longint;
	a:array[1..12] of longint;
procedure put(x:longint);
begin
	writeln(-x);
	halt;
end;
begin
	//assign(input,'1096.in');reset(input);
	//assign(output,'.out');rewrite(output);

	for i:=1 to 12 do read(a[i]);
	ans:=0;
	for i:=1 to 12 do begin
		inc(ans,300);
		dec(ans,a[i]);
		if ans<0 then put(i);
		inc(tot,ans div 100*100);
		ans:=ans mod 100;
	end;
	writeln(tot div 5*6+ans);
end.
