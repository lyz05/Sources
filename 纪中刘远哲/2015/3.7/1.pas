var	ans,l,r,p:longint;
	flag:array[1..100000000] of boolean;
procedure dfs(dep,a,b:longint);
var	i:longint;
begin
	if dep>p then exit;
	if (l<=a) and (a<=r) and (flag[a]) then begin
		inc(ans);
		flag[a]:=false;
	end;
	for i:=0 to 1 do begin
		if odd(i) then dfs(dep+1,a,b+1) else dfs(dep+1,a*b,b);
	end;
end;
begin
	fillchar(flag,sizeof(flag),true);
	ans:=0;
	readln(l,r,p);
	//dfs(0,1,0);
	if p<=2 then ans:=0 else dfs(2,1,2);
	writeln(ans);
end.
