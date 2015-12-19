var	i,j,k,m,n:longint;
	a:array[1..2,1..maxn] of longint;
procedure dfs(x,y,k:longint);
var	i:longint;
begin
	if (x>n) then begin
		x:=1;inc(y);
	end;
	if y>2 then begin
		inc(ans);
		exit;
	end;
	for i:=1 to k do 
end;
begin
	readln(n,k);
	dfs(1,1);
end.
