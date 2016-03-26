var	m,n,i,j,k:longint;
	plane:array[1..maxn] of circle;
	mark:array[1..maxn,0..1] of longint;
	map:array[1..maxn,1..maxn] of longint;
	can:boolean;
procedure clear;
var	i:longint;
begin
	fillchar(map,sizeof(map),255);
	for i:=1 to n do fillchar(mark[i],sizeof(mark[i]),0);
end;
procedure print;
begin
	if can then writeln('YES') else writeln('NO');
end;
begin
	assign(input,'3956.in');reset(input);
	//assign(output,'.out');rewrite(output);
	while not eof do begin
		clear;
		scanf;
		solve;
		print;
	end;
end.
