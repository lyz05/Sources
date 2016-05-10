uses	math;
const	mo=1000000000+7;maxm=100;
var	i,j,k,m,n,s,t:longint;
	a:array[1..maxm] of longint;
	ans:int64;
procedure dfs(dep:longint);
var	i,maxi:longint;
begin
	if s<0 then exit;
	if dep>m then begin
		ans:=(ans+1) mod mo;
		exit;
	end;
	if dep<=n then maxi:=min(t,s) else maxi:=s;
	for i:=1 to maxi do begin
		a[dep]:=i;
                dec(s,i);
			dfs(dep+1);
                inc(s,i);
		a[dep]:=0;
	end;
end;
begin
	assign(input,'1.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(s,t,n,m);
	dfs(1);
	writeln(ans);
end.
