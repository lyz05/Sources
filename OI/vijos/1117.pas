var	i,j,k,m,n,tot:longint;
procedure dfs(now,last,dep:longint);
var	i:longint;
begin
	if dep=k then begin
		inc(tot);
	end;
	for i:=last to now div 2 do begin
		dfs(now-i,i,dep+1);
	end;
end;
begin
	readln(n,k);
	dfs(n,1,1);
	writeln(tot);
end.
