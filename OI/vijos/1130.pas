var	i,j,k,m,n,ans:longint;
procedure dfs(x:longint);
var	i:longint;
begin
	for i:=1 to x div 2 do begin
		inc(ans);
		dfs(i);
	end;
end;
begin
	readln(n);
	dfs(n);
	writeln(ans+1);
end. 
