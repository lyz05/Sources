const	maxn=500+5;
var	i,j,k,m,n,sum:longint;
	a:array[1..maxn+1] of longint;
	mark:array[0..maxn+1] of longint;
begin
	assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	sum:=0;
	readln(n);
	for i:=1 to n+1 do begin
		readln(a[i]);
		inc(sum,a[i]);
	end;
	for i:=1 to n+1 do begin
		if odd(sum-a[i]) then continue;
		inc(mark[0]);
		mark[mark[0]]:=i;	
	end;
	writeln(mark[0]);
	for i:=1 to mark[0] do writeln(mark[i]);
end.
