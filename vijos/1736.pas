const	maxn=10000;
var	i,j,k,m,n,x,y:longint;
	a:array[1..maxn,1..4] of longint;
begin
	assign(input,'1736.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n);
	for i:=1 to n do begin
		for j:=1 to 4 do read(a[i,j]);
		inc(a[i,3],a[i,1]);
		inc(a[i,4],a[i,2]);
	end;
	readln(x,y);
	for i:=n downto 1 do begin
		if (x>=a[i,1])and(x<=a[i,3])and(y>=a[i,2])and(y<=a[i,4])
		then begin
			writeln(i);
			halt;
		end;
	end;
	writeln(-1);
end.
