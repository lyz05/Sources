var	n,k,l,r,ans:longint;
function gcd(x,y:longint):longint;
begin
	if y=0 then exit(x) else exit(gcd(y,x mod y));
end;
procedure dfs(dep,g:longint);
var	i:longint;
begin
	if g<k then exit;
	if dep>n then begin
		if g=k then inc(ans);
		exit;
	end;
	for i:=l to r do begin
		if dep=1 then g:=i;
		dfs(dep+1,gcd(g,i));
	end;
end;
begin
	assign(input,'number.in');reset(input);
	assign(output,'number.out');rewrite(output);

	readln(n,k,l,r);
	ans:=0;
	dfs(1,k);
	writeln(ans);

	close(input);close(output);
end.
