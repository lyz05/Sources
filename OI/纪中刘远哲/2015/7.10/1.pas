uses	math;
const	maxn=1000;maxm=1000;
var	i,j,k,m,n:longint;
	map,f:array[0..maxn,0..maxm] of longint;
begin
	assign(input,'1.in');reset(input);
	readln(n,m);
	for i:=1 to n do 
		for j:=1 to m do read(map[i,j]);
	
	fillchar(f,sizeof(f),125);
	f[0,1]:=0;f[1,0]:=0;
	for i:=1 to n do 
		for j:=1 to m do begin
			f[i][j]:=min(f[i,j-1],f[i-1,j]);
			f[i][j]:=max(f[i][j],map[i][j]);
		end;
	writeln(f[n][m]);
end.
