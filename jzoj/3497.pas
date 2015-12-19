uses	math;
const	mo=1000000007;maxn=200+1;maxd=200+1;
var	i,j,k,n,d:longint;
	f:array[0..maxd,0..maxn] of int64;
	c:array[0..2*maxn,0..2*maxn] of longint;
	ans:int64;
begin
	assign(input,'3497.in');reset(input);
	
	readln(d,n);
	c[0][0]:=1;
	for i:=0 to 2*n+2 do c[i][0]:=1;
	for i:=1 to 2*n do 
		for j:=1 to i do 
			c[i,j]:=(c[i-1,j-1]+c[i-1,j]) mod mo;

	f[0][0]:=1;
	for i:=1 to d do begin
		for j:=0 to n do begin
			for k:=0 to j do begin
				f[i,j]:=(f[i,j]+((f[i-1,j-k]*c[2*j,2*k]) mod mo*c[2*k,k]) mod mo) mod mo;
			end;
		end;
	end;
	ans:=0;
	ans:=f[d][n];
	writeln(ans);
end.
